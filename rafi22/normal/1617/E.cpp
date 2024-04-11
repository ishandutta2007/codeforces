#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[200007];
unordered_map<int,vector<int>>G;
unordered_map<int,int>id;
unordered_map<int,bool>was;
int mx,p;

void dfs(int v,int o,int d)
{
    if(d>mx&&id[v])
    {
        mx=d;
        p=v;
    }
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v,d+1);
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            id[a[i]]=i;
            int x=a[i];
            while(x)
            {
                int o;
                for(int j=0;j<=30;j++)
                {
                    if((1<<j)>=x)
                    {
                        o=(1<<j)-x;
                        break;
                    }
                }
                if(!was[x])
                {
                    G[o].pb(x);
                    G[x].pb(o);
                }
                was[x]=1;
                x=o;
            }
        }
        mx=-1;
        dfs(0,-1,0);
        mx=-1;
        int x=id[p];
        dfs(p,-1,0);
        int y=id[p];
        cout<<x<<" "<<y<<" "<<mx;
    }

    return 0;
}