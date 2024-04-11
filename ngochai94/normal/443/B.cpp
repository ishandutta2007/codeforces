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

string s;
int k;

int main() {
    ios::sync_with_stdio(0);
    cin >> s >> k;
    int n = s.size();
    int ans = 2 * min(k, (n + k) / 2);
    // BUG(ans);
    FOR (len, 1, n / 2) {
        REP (i, n) if (i + 2 * len <= n) {
            bool flag = false;
            REP (j, len) if (s[i + j] != s[i + j + len]) {
                flag = true;
                break;
            }
            if (!flag) ans = max(ans, 2 * len);
        }
    }
    FOR (len, 1, n / 2) {
        REP (st, n) if (st + len <= n - len) {
            bool flag = false;
            REP (i, len) if (s[st + i] != s[n - len + i]) {
                flag = true;
                break;
            }
            if (!flag && k >= n - len - st - len) ans = max(ans, 2 * (n - len - st));
        }
    }
    cout << ans;
}