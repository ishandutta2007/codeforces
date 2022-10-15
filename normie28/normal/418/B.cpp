#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define inf (1ll<<60)
#define ll long long
#define pll pair<long long,long long>
 
long long n,m,b,cost[111],need[111],ans,cur,solve,prob,fmask[111],dp[1<<22],id;
vector<int> fri[111];
pair<long long,int> screen[111];
 
long long solvee(int cap)
{
    For(mask,1,1<<m)
    {
 
        id=screen[cap].second;
        dp[mask]=min(dp[mask],cost[id]+dp[mask&(~fmask[id])]);
    }
    return dp[(1<<m)-1];
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ans=inf;
    reset(fmask,0);
    cin>>n>>m>>b;
    For(i,0,1<<m) dp[i]=inf;
    dp[0]=0;
    For(i,0,n)
    {
        cin>>cost[i]>>need[i]>>solve;
        while(solve--)
        {
            cin>>prob;
            prob--;
            fri[i].pb(prob);
            fmask[i]|=1<<prob;
        }
        screen[i]={need[i],i};
    }
    sort(screen,screen+n);
    For(i,0,n) ans=min(ans,solvee(i)+b*screen[i].first);
    if(ans==inf) cout<<-1;
    else cout<<ans;
}