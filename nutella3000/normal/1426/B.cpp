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
        int n, m;
        cin >> n >> m;
        bool have = false;
        for(int i = 0;i < n;i++) {
            int v1, v2, v3, v4;
            cin >> v1 >> v2 >> v3 >> v4;
            if (v2 == v3) have = true;
        }

        if (m % 2 == 0 && have) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}