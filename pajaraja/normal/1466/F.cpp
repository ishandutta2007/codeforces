#include <bits/stdc++.h>
#define MAXN 500007
#define MOD 1000000007
using namespace std;
int dsu[MAXN];
vector<int> g[MAXN],vr;
int root(int u)
{
    while(dsu[u]!=u)
    {
        dsu[u]=dsu[dsu[u]];
        u=dsu[u];
    }
    return u;
}
void connect(int u,int v,int ind)
{
    int a=root(u),b=root(v);
    if(a==b) return;
    dsu[a]=b;
    vr.push_back(ind);
}
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    iota(dsu,dsu+n+2,0);
    for(int i=1;i<=m;i++)
    {
        int k; scanf("%d",&k);
        if(k==1)
        {
            int t; scanf("%d",&t);
            connect(t,n+1,i);
        }
        else
        {
            int t1,t2; scanf("%d%d",&t1,&t2);
            connect(t1,t2,i);
        }
    }
    long long sol=1;
    for(int i=0;i<vr.size();i++) sol=(sol*2)%MOD;
    printf("%lld %d\n",sol,vr.size());
    for(int i=0;i<vr.size();i++) printf("%d ",vr[i]);
}