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

vector <int> G[100007];
int odw[100007];
int s[100007];
int tab[100007];
vector <int> vec;
vector <int> vec1;
int n,m;

void dfs(int v)
{
    odw[v]=1;
    s[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            dfs(u);
            s[v]+=s[u];
        }
    }
    if(v!=1)
    {
        vec.pb((n-s[v])*s[v]);
    }
}
void clean()
{
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
        odw[i]=0;
        vec1.clear();
        vec.clear();
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
        int a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1);
        sort(vec.begin(),vec.end(),greater<int>());
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a;
            vec1.push_back(a);
        }
        int sum=1;
        sort(vec1.begin(),vec1.end(),greater<int>());
        for(int i=0;i<=max((int)0,m-n+1);i++)
        {
            sum*=vec1[i];
            sum%=mod;
        }
        int it=max((int)0,m-n+1)+1;
        int ans=0;
        ans+=sum*vec[0];
        ans%=mod;
       // cout<<sum<<endl;
        for(int i=1;i<vec.size();i++)
        {
            if(it<m) ans+=(vec1[it++]*vec[i])%mod;
            else ans+=vec[i];
            ans%=mod;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
        clean();
    }

    return 0;
}