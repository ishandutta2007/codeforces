#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool good = false;
        int Min = inf, last = inf;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            if (last > a[i]) {
                Min -= last - a[i];
            }
            last = a[i];
        }

        if (Min < 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}