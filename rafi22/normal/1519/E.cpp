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

const int N=200007;

int a[N],b[N],c[N],d[N];
vector<pair<int,int>>G[2*N];
bool odw[2*N];
int nr[2*N],cnt=1;
vector<pair<int,int>>ans;

pair<int,int> skroc(pair<int,int> F)
{
    int g=__gcd(F.st,F.nd);
    F.st/=g;
    F.nd/=g;
    return F;
}
map<pair<int,int>,int>id;

int dfs(int v)
{
    nr[v]=cnt++;
    odw[v]=1;
    int last=-1;
    for(auto u:G[v])
    {
        if(!odw[u.st])
        {
            int x=dfs(u.st);
            if(x!=-1) ans.pb({x,u.nd});
            else if(last!=-1)
            {
                ans.pb({last,u.nd});
                last=-1;
            }
            else last=u.nd;
        }
        else if(nr[v]<nr[u.st])
        {
            if(last!=-1)
            {
                ans.pb({last,u.nd});
                last=-1;
            }
            else last=u.nd;
        }
    }
    return last;
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
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i]>>d[i];
            vec.pb(skroc({(a[i]+b[i])*d[i],b[i]*c[i]}));
            vec.pb(skroc({a[i]*d[i],b[i]*(c[i]+d[i])}));
        }
        sort(vec.begin(),vec.end());
        int it=1;
        id[vec[0]]=1;
        for(int i=1;i<sz(vec);i++)
        {
            if(vec[i]!=vec[i-1]) it++;
            id[vec[i]]=it;
        }
        for(int i=1;i<=n;i++)
        {
            int u=id[skroc({(a[i]+b[i])*d[i],b[i]*c[i]})];
            int v=id[skroc({a[i]*d[i],b[i]*(c[i]+d[i])})];
            G[u].pb({v,i});
            G[v].pb({u,i});
        }
        for(int i=1;i<=it;i++) if(!odw[i]) dfs(i);
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;

    }

    return 0;
}