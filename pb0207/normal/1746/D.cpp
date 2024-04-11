#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int T;

int n,k;

vector<int>g[N];

ll f[N][2],s[N];

int mn[N],mx[N];

void dfs(int x)
{
    f[x][0]=f[x][1]=-5e18;
    int d=g[x].size();
    ll sum=0;
    vector<ll>val;
    for(auto v:g[x])
    {
        mn[v]=mn[x]/d;
        mx[v]=(mx[x]+d-1)/d;
        dfs(v);
        sum+=f[v][0];
        val.push_back(f[v][1]-f[v][0]);
    }
    f[x][0]=sum+1ll*mn[x]*s[x],f[x][1]=sum+1ll*mx[x]*s[x];
    if(d)
    {
        sort(val.begin(),val.end());
        reverse(val.begin(),val.end());
        for(int i=1;i<val.size();i++)
            val[i]+=val[i-1];
        if(mn[x]-mn[x]/d*d)
            f[x][0]+=val[mn[x]-mn[x]/d*d-1];
        if(mx[x]-mn[x]/d*d)
            f[x][1]+=val[mx[x]-mn[x]/d*d-1];
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;
            scanf("%d",&p);
            g[p].push_back(i);
        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&s[i]);
        mn[1]=mx[1]=k;
        dfs(1);
        printf("%lld\n",f[1][1]);
    }
}