#include <iostream>
#include <deque>

using namespace std;

typedef long long ll;

int n, w;
ll r[1222333];
int a[1222333];
ll e[1222333];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) cin >> a[j];
        if (2*k <= w) {
            int u = 0;
            for (int j = 1; j <= k; j++) {
                u = max(u,a[j]);
                if (u < 0) continue;
                r[j] += u;
            }
            u = 0;
            int c = w;
            for (int j = k; j >= 1; j--) {
                u = max(u,a[j]);
                if (u < 0) continue;
                r[c--] += u;
            }
            int x1 = k+1;
            int x2 = w-k;
            if (u > 0 && x1 <= x2) {
                e[x1] += u;
                e[x2+1] -= u;
            }
        } else {
            deque<pair<int,int>> d;
            for (int i = 1; i <= w; i++) {
                if (i <= k) {
                    while (d.size() && d.back().first <= a[i]) d.pop_back();
                    d.push_back({a[i],i});
                }
                if (d.size() && i+k-d.front().second > w) d.pop_front();
                int z = d.front().first;
                if (z < 0 && (i+1+k-1 <= w || i-1-k+1 >= 1)) continue;
                r[i] += z;
            }
        }
    }
    ll x = 0;
    for (int i = 1; i <= w; i++) {
        x += e[i];
        r[i] += x;
        cout << r[i] << " ";
    }
    cout << "\n";
}