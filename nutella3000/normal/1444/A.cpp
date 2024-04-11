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
        int p, q;
        cin >> p >> q;
        int x = p;

        int res = x;
        if (x % q == 0) {
            int w = q;
            res = -inf;
            vector<int> a;
            for(int i = 2;i * i <= q;i++) {
                if (q % i == 0) {
                    a.emplace_back(i);
                    while(q % i == 0) q /= i;
                }
            }

            if (q != 1) a.emplace_back(q);

            for(int i : a) {
                int v = x;
                while(v % w == 0) v /= i;
                res = max(res, v);
            }
        }

        cout << res << endl;
    }
}