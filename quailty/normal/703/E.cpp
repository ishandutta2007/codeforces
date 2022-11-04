#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const int MAXD=7005;
const int INF=0x3f3f3f3f;
#define ft first
#define sd second
ll a[MAXN];
vector<pair<ll,int> >pk;
vector<int>pa[MAXN],res;
pair<int,ll>dp[MAXN][MAXD];
int pre[MAXN][MAXD];
inline int encode(vector<int>&p)
{
    int res=0;
    for(int i=0;i<(int)pk.size();i++)
        res=res*(pk[i].sd+1)+p[i];
    return res;
}
inline void decode(int x,vector<int>&res)
{
    res.resize(pk.size());
    for(int i=(int)pk.size()-1;i>=0;i--)
    {
        res[i]=x%(pk[i].sd+1);
        x/=pk[i].sd+1;
    }
}
int main()
{
    int n,d=1;
    ll k;
    scanf("%d%I64d",&n,&k);
    for(ll i=2;i*i<=k;i++)if(k%i==0)
    {
        int cnt=0;
        while(k%i==0)k/=i,cnt++;
        pk.push_back(make_pair(i,cnt));
        d*=cnt+1;
    }
    if(k!=1)
    {
        pk.push_back(make_pair(k,1));
        d*=2;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        ll t=a[i];
        for(int j=0;j<(int)pk.size();j++)
        {
            int cnt=0;
            while(t%pk[j].ft==0)t/=pk[j].ft,cnt++;
            pa[i].push_back(cnt);
        }
    }
    if((int)pk.size()==0)
    {
        int loc=1;
        for(int i=1;i<=n;i++)
            if(a[loc]>a[i])loc=i;
        return 0*printf("1\n%d",loc);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<d;j++)
            dp[i][j]=make_pair(INF,0);
    dp[0][d-1]=make_pair(0,0);
    vector<int>pj;
    for(int i=1;i<=n;i++)
        for(int j=0;j<d;j++)
        {
            if(dp[i][j]>dp[i-1][j])
            {
                dp[i][j]=dp[i-1][j];
                pre[i][j]=j;
            }
            decode(j,pj);
            for(int k=0;k<(int)pk.size();k++)
                pj[k]-=min(pj[k],pa[i][k]);
            int tj=encode(pj);
            if(dp[i][tj]>make_pair(dp[i-1][j].ft+1,dp[i-1][j].sd+a[i]))
            {
                dp[i][tj]=make_pair(dp[i-1][j].ft+1,dp[i-1][j].sd+a[i]);
                pre[i][tj]=j;
            }
        }
    if(dp[n][0].ft==INF)return 0*printf("-1\n");
    int p=n,q=0;
    while(p>0)
    {
        int r=pre[p][q];
        if(r!=q)res.push_back(p);
        p--,q=r;
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}