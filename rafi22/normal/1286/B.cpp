#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
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

int s[2007];
int c[2007];
vector<int>G[2007];
int o[2007];
int ans[2007];
int d[2007];
bool odw[2007];

void dfs(int v)
{
    for(auto u:G[v])
    {
        d[u]=d[v]+1;
        dfs(u);
        s[v]+=s[u]+1;
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
        int n,r;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>o[i]>>c[i];
            G[o[i]].pb(i);
            if(o[i]==0) r=i;
        }
        dfs(r);
        for(int i=n;i>0;i--)
        {
            int mn=inf,p=-1;
            for(int j=1;j<=n;j++)
            {
                if(odw[j]||d[j]>=mn||s[j]!=c[j]) continue;
                mn=d[j];
                p=j;
            }
            if(p==-1)
            {
                cout<<"NO";
                return 0;
            }
            ans[p]=i;
            odw[p]=1;
            while(true)
            {
                p=o[p];
                if(p==0) break;
                s[p]--;
            }
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}