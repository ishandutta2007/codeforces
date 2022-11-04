#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=16;
vector<pair<int,int> > e[MAXN+5];
int res[MAXN+5],usd[MAXN+5];
ll dp[(1<<MAXN)+5];
int getKth(int k)
{
    int res=-1;
    while(k--)
    {
        res++;
        while(usd[res])res++;
    }
    return res;
}
ll cal(int p,int n)
{
    for(int i=0;i<p;i++)
        for(int j=0;j<(int)e[i].size();j++)
        {
            int t=e[i][j].first;
            if(t<p && (res[i]-res[t])*e[i][j].second<0)
                return 0;
        }
    n-=p;
    memset(dp,0,(1<<n)*sizeof(ll));
    dp[0]=1;
    for(int i=0;i<(1<<n);i++)
    {
        int d=getKth(__builtin_popcount(i)+1);
        for(int j=0;j<n;j++)if(~i&(1<<j))
        {
            bool isok=1;
            for(int k=0;k<(int)e[j+p].size();k++)
            {
                int t=e[j+p][k].first;
                if(t<p && (d-res[t])*e[j+p][k].second<0)isok=0;
                if(t>=p && (i&(1<<(t-p))) && e[j+p][k].second<0)isok=0;
                if(t>=p && (~i&(1<<(t-p))) && e[j+p][k].second>0)isok=0;
            }
            if(isok)dp[i|(1<<j)]+=dp[i];
        }
    }
    return dp[(1<<n)-1];
}
int main()
{
    int n,m;
    ll y;
    scanf("%d%lld%d",&n,&y,&m);
    y-=2000;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        e[a].push_back(make_pair(b,-1));
        e[b].push_back(make_pair(a,1));
    }
    if(cal(0,n)<y)return 0*printf("The times have changed");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)if(!usd[j])
        {
            res[i]=j;
            usd[j]=1;
            ll tmp=cal(i+1,n);
            if(y>tmp)y-=tmp;
            else break;
            usd[j]=0;
        }
    for(int i=0;i<n;i++)
        printf("%d ",res[i]+1);
    return 0;
}