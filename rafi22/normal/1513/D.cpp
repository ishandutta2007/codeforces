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

const bool multi=1;

int a[200007];
int o[200007];
int s[200007];
int ile;

int Find(int v)
{
    while(true)
    {
        if(o[v]==v) return v;
        v=o[v];
    }
}
void Onion(int u,int v)
{
    ile--;
    if(s[u]<=s[v])
    {
        o[u]=v;
        s[v]+=s[u];
    }
    else
    {
        o[v]=u;
        s[u]+=s[v];
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
        int n,p,ans=0;
        cin>>n>>p;
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vec.pb({a[i],i});
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<=n;i++)
        {
            o[i]=i;
            s[i]=1;
        }
        ile=n;
        for(auto x:vec)
        {
            if(x.st>p) break;
            for(int i=x.nd-1;i>0;i--)
            {
                if(a[i]%a[x.nd]==0&&Find(i)!=Find(x.nd))
                {
                    ans+=x.st;
                    Onion(Find(i),Find(x.nd));
                }
                else break;
            }
            for(int i=x.nd+1;i<=n;i++)
            {
                if(a[i]%a[x.nd]==0&&Find(i)!=Find(x.nd))
                {
                    ans+=x.st;
                    Onion(Find(i),Find(x.nd));
                }
                else break;
            }
        }
        ans+=(ile-1)*p;
        cout<<ans<<endl;
    }

    return 0;
}