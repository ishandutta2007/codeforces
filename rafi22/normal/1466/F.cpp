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

int o[500007];
int s[500007];
bool p[500007];
int Find(int a)
{
    while(true)
    {
        if(o[a]==a)
        {
            return a;
        }
        a=o[a];
    }
}
void Union(int u,int v)
{
    if(s[u]<=s[v])
    {
        o[u]=v;
        s[v]+=s[u];
        p[v]=p[v]|p[u];
    }
    else
    {
        o[v]=u;
        s[u]+=s[v];
        p[u]=p[v]|p[u];
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            o[i]=i;
            s[i]=1;
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            int k,a,b;
            cin>>k;
            if(k==1)
            {
                cin>>a;
                if(!p[Find(a)])
                {
                    p[Find(a)]=1;
                    ans.pb(i);
                }
            }
            else
            {
                cin>>a>>b;
                if(!(p[Find(a)]&&p[Find(b)])&&Find(a)!=Find(b))
                {
                    Union(Find(a),Find(b));
                    ans.pb(i);
                }
            }
        }
        int res=1;
        for(int i=0;i<sz(ans);i++) res=res*2%mod;
        cout<<res<<" "<<sz(ans)<<endl;
        for(auto x:ans) cout<<x<<" ";
    }

    return 0;
}