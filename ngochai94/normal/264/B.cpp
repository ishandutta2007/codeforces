#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

int n, lis[100005], dp[100005], ans;
vector<int> sieve[100005];

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    sort(lis, lis + n);
    FOR (i, 2, 100000) if (sieve[i].empty()) {
        sieve[i].pb(i);
        for (long long j = i * 2; j <= 100000; j += i) sieve[j].pb(i);
    }
    // for (int i: sieve[60]) cout << i << endl;
    REP (i, n) {
        int cur = 0;
        for (int j: sieve[lis[i]]) cur = max(cur, dp[j]);
        cur++;
        for (int j: sieve[lis[i]]) dp[j] = cur;
        ans = max(ans, cur);
    }
    cout << ans;
}