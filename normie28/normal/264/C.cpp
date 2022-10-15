#include<bits/stdc++.h>
using namespace std;
 
#define si(n) cin>>n
#define MAX 100005
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n" 
 
int col[MAX],val[MAX],a,b,n,q;
ll dp[MAX];
 
void solve()
{
    ll mx1=0,mx2=0,c1=0,c2=0;
    for(int i=1;i<=n;i++){
        if(dp[col[i]] !=-INF)dp[col[i]]=max(dp[col[i]],dp[col[i]]+(ll)val[i]*a);
 
        dp[col[i]]=max(dp[col[i]],(ll)b*val[i]);
        if(c1 !=col[i]){
            dp[col[i]]=max(dp[col[i]],mx1+(ll)val[i]*b);
        }
        else {
            dp[col[i]]=max(dp[col[i]],mx2+(ll)val[i]*b);
        }
 
        if(dp[col[i]]>mx1){
            if(c1 == col[i])mx1=dp[col[i]];
            else {
                c2=c1,mx2=mx1;
                mx1=dp[col[i]],c1=col[i];
            }
        }
        else if(col[i] != c1 && dp[col[i]]>mx2){
            mx2=dp[col[i]];c2=col[i];
        }
    }
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int i,j;
    si(n);si(q);
    for(i=1;i<=n;i++)si(val[i]);
    for(i=1;i<=n;i++)si(col[i]);
    while(q--){
        si(a);si(b);
        memset(dp,-INF,sizeof(dp));
        solve();
        ll mx=0;
        for(i=1;i<=n;i++)mx=max(mx,dp[i]);
        cout<<mx<<endl;
    }
}