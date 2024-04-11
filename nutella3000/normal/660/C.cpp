#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;

vector<int> res;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    res.resize(n);

    for(int i = 0;i < n;i++)
        cin >> a[i];

    int l = -1, r = n + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        int cnt = 0;
        int left = -1, right = -1;

        for(int i = 0;i < mid;i++) cnt += 1 - a[i];

        for(int i = mid;i <= n;i++) {
            if (cnt <= k) {
                right = i - 1;
                left = i - mid;
            }

            if (i == n)
                continue;
            cnt += (1 - a[i]) - (1 - a[i - mid]);
        }

        if (left != -1) {
            for(int i = 0;i < n;i++)
                res[i] = a[i];

            for(int i = left;i <= right;i++) 
                res[i] = 1;

            l = mid;
        }else
            r = mid;
    }

    cout << l << endl;
    for(int i : res) 
        cout << i << " ";
}