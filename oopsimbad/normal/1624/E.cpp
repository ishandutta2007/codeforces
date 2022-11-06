#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
    int asdf; cin >> asdf;
    while(asdf--) {
        int n, m; cin >> n >> m;

        pii loc2[10][10];
        pii loc3[10][10][10];

        F0R(i, 10)
            F0R(j, 10) {
                loc2[i][j].f = -1;
                F0R(k, 10)
                    loc3[i][j][k].f = -1;
            }

        F0R(_, n) {
            string s; cin >> s;
            F0R(i, m-1) {
                loc2[s[i]-'0'][s[i+1]-'0'].f = _;
                loc2[s[i]-'0'][s[i+1]-'0'].s = i;
            }
            F0R(i, m-2) {
                loc3[s[i]-'0'][s[i+1]-'0'][s[i+2]-'0'].f = _;
                loc3[s[i]-'0'][s[i+1]-'0'][s[i+2]-'0'].s = i;
            }
        }
        string tar; cin >> tar;

        bool dp[m+1];
        pair<int, pii> used[m+1];
        F0R(i, m) dp[i] = false;
        dp[m] = true;

        F0Rd(i, m-1) {
            if(i != m-2 && dp[i+3] && loc3[tar[i]-'0'][tar[i+1]-'0'][tar[i+2]-'0'].f != -1) {
                dp[i] = true;
                used[i].f = 3;
                used[i].s = loc3[tar[i]-'0'][tar[i+1]-'0'][tar[i+2]-'0'];
            }
            if(dp[i+2] && loc2[tar[i]-'0'][tar[i+1]-'0'].f != -1) {
                dp[i] = true;
                used[i].f = 2;
                used[i].s = loc2[tar[i]-'0'][tar[i+1]-'0'];
            }
        }

        if(dp[0]) {
            vector<pair<pii, int>> ans;
            
            int i = 0;
            while(i != m) {
                ans.pb(mp(mp(used[i].s.s, used[i].s.s+used[i].f), used[i].s.f));
                i += used[i].f;
            }
            
            cout << ans.size() << endl;
            for(auto x : ans)
                cout << x.f.f+1 << " " << x.f.s << " " << x.s+1 << endl;
        } else cout << -1 << endl;
    }
}