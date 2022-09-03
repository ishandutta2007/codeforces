#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,p,d,din[611],dout[611];
ll dp[611][611],a[611][611];
vector<int>con[611],rev[611],s,t;
ll dfs(int x,int y)
{
    if(x==y)return dp[x][y]=1;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=0;
    for(int i=0;i<rev[y].size();i++)
    {
        dp[x][y]=(dp[x][y]+dfs(x,rev[y][i]))%p;
    }
    return dp[x][y];
}
ll kissme(ll x,ll k)
{
    int ans=1;
    while(k>0)
    {
        if(k&1)ans=ans*x%p;
        k=k/2;
        x=x*x%p;
    }
    return ans;
}
ll cal()
{
    bool neg=0;
    for(int i=0;i<d;i++)
    {
        int ok=-1;
        for(int j=i;j<d;j++)if(a[j][i]!=0){ok=j;break;}
        if(ok==-1)return 0;
        if(ok!=i)
        {
            for(int j=0;j<d;j++)swap(a[i][j],a[ok][j]);
            neg^=1;
        }
        for(int j=i+1;j<d;j++)
        {
            ll coef=(p-a[j][i])*kissme(a[i][i],p-2)%p;
            for(int k=i;k<d;k++)a[j][k]=(a[j][k]+a[i][k]*coef)%p;
        }
    }
    ll ans=(neg?(p-1):1);
    for(int i=0;i<d;i++)ans=ans*a[i][i]%p;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>p;int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        con[x].PB(y);
        rev[y].PB(x);
        din[y]++;
        dout[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(din[i]==0&&dout[i]>0)s.PB(i);
        if(din[i]>0&&dout[i]==0)t.PB(i);
    }d=s.size();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=-1;
    for(int i=0;i<d;i++)for(int j=0;j<d;j++)a[i][j]=dfs(s[i],t[j]);
    ll ans=cal();
    bool neg=0;
    for(int i=1;i<=n;i++)if(din[i]==0&&dout[i]==0)
    {
        int cnt1=0,cnt2=0;
        for(int j=0;j<d;j++)if(s[j]<i)cnt1++;
        for(int j=0;j<d;j++)if(t[j]<i)cnt2++;
        if(cnt1%2!=cnt2%2)neg^=1;
    }
    if(neg)ans=(p-ans)%p;
    cout<<ans<<endl;
    return 0;
}