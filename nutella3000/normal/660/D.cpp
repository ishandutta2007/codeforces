#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    map<pii, int> b;
    vector<pii> a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            int x = a[i].first - a[j].first;
            int y = a[i].second - a[j].second;

            if (x < 0 || (x == 0 && y < 0)) {
                x = -x;
                y = -y;
            }

            //if (x == 1 && y == 0) cout << i << " " << j << endl;;

            b[{x, y}]++;
        }
    }

    int res = 0;
    for(auto i : b) {
        res += i.second * (i.second - 1) / 2;
        //cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    }

    cout << res / 2;
}