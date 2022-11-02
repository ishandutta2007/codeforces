#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e9 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int res = inf;
        for(int i = 0;i < 10;i++) {
            for(int j = 0;j < 10;j++) {
                bool first = true;
                int new_res = 0;
                for(int k = 0;k < n;k++) {
                    if (first && s[k] == '0' + i) first = false;
                    else if (!first && s[k] == '0' + j) first = true;
                    else new_res++;
                }
                if (first || i == j)
                    res = min(res, new_res);
                //if (new_res == 4) cout << s << " " << i << " " << j << endl;
            }
        }
        cout << res << endl;
    }
}