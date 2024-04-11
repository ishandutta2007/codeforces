#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[500007],b[500007];
vector<pair<int,int>>G[(1<<20)+7];
bool odw[(1<<20)+7];
bool odw1[(1<<20)+7];

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(odw[u.st]) continue;
        dfs(u.st);
    }
}
void dfsEuler(int v,int o)
{
    while(sz(G[v])>0)
    {
        pair<int,int> u=G[v].back();
        G[v].pop_back();
        if(odw1[u.nd/2]) continue;
        odw1[u.nd/2]=1;
        dfsEuler(u.st,u.nd);
    }
    if(o!=-1) cout<<(o^1)-1<<" "<<o-1<<" ";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        for(int j=20;j>=0;j--)
        {
            for(int i=0;i<=1<<20;i++)
            {
                G[i].clear();
                odw[i]=0;
            }
            for(int i=1;i<=n;i++)
            {
                G[a[i]&((1<<j)-1)].pb({b[i]&((1<<j)-1),2*i});
                G[b[i]&((1<<j)-1)].pb({a[i]&((1<<j)-1),2*i+1});
            }
            bool ok=1;
            int xd=0;
            for(int i=0;i<=1<<20;i++)
            {
                if(sz(G[i])%2==1) ok=0;
                if(!odw[i]&&sz(G[i])>0)
                {
                    dfs(i);
                    xd++;
                }
            }
            if(xd>1) ok=0;
            if(ok)
            {
                cout<<j<<endl;
                for(int i=0;i<=1<<20;i++)
                {
                    if(sz(G[i])>0)
                    {
                        dfsEuler(i,-1);
                        break;
                    }
                }
                break;
            }
        }
    }

    return 0;
}