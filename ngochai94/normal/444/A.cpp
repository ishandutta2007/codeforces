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

long long n, m, lis[555], u, v, c; 
double ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    ans = 0;
    FOR (i, 1, n) cin >> lis[i];
    ans = 0;
    while (m--) {
        cin >> u >> v >> c;
        ans = max(ans, 1.0 * (lis[u] + lis[v]) / c);
    }
    cout << setprecision(11) << ans;
}