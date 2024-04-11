#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int n, m;
string s[111];
int mrk[26], cnt;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, n) cin >> s[i];
    long long ans = 1;
    REP (j, m) {
        reset(mrk, 0);
        cnt = 0;
        REP (i, n) {
            if (!mrk[s[i][j] - 'A']) {
                mrk[s[i][j] - 'A'] = 1;
                cnt++;
            }
        }
        ans *= cnt;
        ans %= mod;
    }
    cout << ans;
}