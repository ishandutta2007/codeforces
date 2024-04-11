#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];

        vector<pii> res;

        if (a[0][1] != a[1][0]) {
            if (a[0][1] != a[n - 1][n - 2]) {
                res.emplace_back(1, 0);
                a[1][0] = '1' + '0' - a[1][0];
            }else{
                res.emplace_back(0, 1);
                a[0][1] = '1' + '0' - a[0][1];
            }
        }

        //cout << a[n - 1][n - 2] << " " << a[n - 2][n - 1] << endl;
        if (a[n - 1][n - 2] == a[0][1]) {
            res.emplace_back(n - 1, n - 2);
        }
        if (a[n - 2][n - 1] == a[0][1]) {
            res.emplace_back(n - 2, n - 1);
        }

        cout << res.size() << endl;
        for(pii i : res)
            cout << i.fi + 1 << " " << i.se + 1 << endl;
    }   
}