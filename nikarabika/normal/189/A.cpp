#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int dp[3][4050];

int main(){
	ios_base::sync_with_stdio(false);
    int a[3];
    int n;
    cin>>n;
    rep(i, 3)
        cin>>a[i];
    sort(a, a+3);
    memset(dp[0], -1, sizeof dp[0]);
    memset(dp[1], -1, sizeof dp[1]);
    memset(dp[2], -1, sizeof dp[2]);
    FOR(i, 0, n/a[0])
        dp[0][i*a[0]]=i;
    dp[1][0]=0;
    dp[2][0]=0;
    FOR(i, 1, 2){
        FOR(j, 1, n){
            if(j-a[i]>=0 && dp[i][j-a[i]]>=0)
                dp[i][j]=dp[i][j-a[i]]+1;
            if(dp[i-1][j]>dp[i][j])
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[2][n]<<endl;
	return 0;
}