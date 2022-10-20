#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define ll int
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 20010
#define M 4010
using namespace std;
ll n,p,q,dpl[10010][M],dpr[M],mx[M],mx2[M],ans[N];
vector<pair<ll,ll> > qry[N];
vector<ll> cost[N],val[N];
void solve(ll x)
{
    ll i,j,l;
    for(i=0;i<M;i++)
    {
        dpr[i]=0;
        for(j=0;j<=p;j++)
        {
            dpl[j][i]=0;
        }
    }
    for(i=x-1;i>=x-p&&i>=0;i--)
    {
        for(j=0;j<M;j++)
        {
            dpl[x-i][j]=dpl[x-i-1][j];
        }
        for(l=0;l<cost[i].size();l++)
        {
            for(j=M-1;j>=cost[i][l];j--)
            {
                dpl[x-i][j]=max(dpl[x-i][j],(j>=cost[i][l]?max(dpl[x-i][j-cost[i][l]],dpl[x-i-1][j-cost[i][l]])+val[i][l]:0));
            }
        }
    }
    for(i=x;i<x+p&&i<N;i++)
    {
        for(l=0;l<cost[i].size();l++)
        {
            for(j=M-1;j>=cost[i][l];j--)
            {
                dpr[j]=max(dpr[j],(j>=cost[i][l]?dpr[j-cost[i][l]]+val[i][l]:0));
            }
        }
        mx[0]=dpr[0];
        mx2[0]=dpl[x-max(0,i-p+1)][0];
        for(j=1;j<M;j++)
        {
            mx[j]=max(mx[j-1],dpr[j]);
            mx2[j]=max(mx2[j-1],dpl[x-max(0,i-p+1)][j]);
        }
        for(j=0;j<qry[i].size();j++)
        {
            for(l=0;l<=qry[i][j].F;l++)
            {
                ans[qry[i][j].S]=max(ans[qry[i][j].S],mx[l]+mx2[qry[i][j].F-l]);
            }
        }
    }
    return;
}
int main(){
    ll i,x,y,z,l,r,v;
    scanf("%d%d",&n,&p);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        cost[z].push_back(x);
        val[z].push_back(y);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&r,&v);
        l=max(0,r-p+1);
        qry[r].push_back(make_pair(v,i));
    }
    for(i=0;i*p+1<N;i++)
    {
        solve(i*p);
    }
    for(i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}