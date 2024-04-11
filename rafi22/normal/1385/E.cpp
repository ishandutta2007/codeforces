#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

vector <int> G[200007];
vector <int> RG[200007];
vector <pair<int,int>> UG[200007];
int ile[200007];
int odw[200007];
int odw1[200007];
int spojna[200007];
pair<int,int> ans[200007];
int c=1,counter=1;
bool ok=1;
deque <int> kolejka;
vector <int> stos;
int q;


void dfs(int v)
{
    odw[v]=1;
    for(auto u:RG[v])
    {
        if(!odw[u]) dfs(u);
    }
    stos.push_back(v);
}

void dfs1(int v)
{
    spojna[v]=counter;
    q++;
    for(auto u:G[v])
    {
        if(spojna[u]==0)
        {
            dfs1(u);
        }
    }
}

void clean(int n)
{
    for(int i=0;i<n+4;i++)
    {
        G[i].clear();
        RG[i].clear();
        UG[i].clear();
        odw[i]=0;
        odw1[i]=0;
        spojna[i]=0;
        ans[i]={0,0};
        ile[i]=0;
        c=1;
        counter=1;
        ok=1;
        stos.clear();
    }
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
        int n,m,a,b,y=1;
        bool x;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>x>>a>>b;
            if(x)
            {
                G[a].pb(b);
                RG[b].pb(a);
                ile[b]++;
                ans[i]={a,b};
            }
            else
            {
                UG[a].pb({b,i});
                UG[b].pb({a,i});
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i]) dfs(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(spojna[stos[i]]==0)
            {
                q=0;
                dfs1(stos[i]);
                if(q>1) ok=0;
                counter++;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(ile[i]==0) kolejka.pb(i);
        }
        while(!kolejka.empty())
        {
            int v=kolejka[0];
            kolejka.pop_front();
            odw1[v]=1;
            for(auto u:G[v])
            {
                ile[u]--;
                if(ile[u]==0) kolejka.pb(u);
            }
            for(auto u:UG[v])
            {
                if(!odw1[u.st])
                {
                    ans[u.nd]= {v,u.st};
                }
            }
        }
        if(!ok) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0; i<m; i++)
            {
                cout<<ans[i].st<<" "<<ans[i].nd<<endl;
            }
        }
        clean(max(n,m));
    }

    return 0;
}