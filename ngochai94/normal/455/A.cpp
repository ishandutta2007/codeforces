#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

long long n, cnt[100005], dp[100005];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n)
    {
        long long val;
        cin >> val;
        cnt[val] += val;
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    FOR (i, 2, 100004) dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i]);
    cout << dp[100004];
}