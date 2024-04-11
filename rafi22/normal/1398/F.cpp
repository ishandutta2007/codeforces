#include <bits/stdc++.h>

//#define int long long
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

vector<int>usun[1000007];
int o[1000007];

int Find(int v)
{
    vector<int>p;
    int x=-1;
    while(true)
    {
        p.pb(v);
        if(o[v]==v)
        {
            x=v;
            break;
        }
        v=o[v];
    }
    for(auto u:p) o[u]=x;
    return x;
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
        string s;
        cin>>s;
        s='#'+s;
        int last0=n+1,last1=n+1;
        for(int i=n;i>0;i--)
        {
            if(s[i]=='0') last0=i;
            if(s[i]=='1') last1=i;
            usun[max(last0,last1)-i+1].pb(i);
        }
        for(int i=1;i<=n+1;i++) o[i]=i;
        for(int i=1;i<=n;i++)
        {
            for(auto x:usun[i]) o[x]=Find(x+1);
            int p=1,ans=0;
            while(p<=n)
            {
                p=Find(p);
                if(p<=n) ans++;
                p+=i;
            }
            cout<<ans<<" ";
        }

    }

    return 0;
}