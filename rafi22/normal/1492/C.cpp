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

int pref[200007];
int suf[200007];
int mn[200007];
int mx[200007];


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
        string s,t;
        cin>>s>>t;
        s='#'+s;
        t='#'+t;
        int it=1;
        for(int i=1;i<=m;i++) mn[i]=inf;
        for(int i=1;i<=n;i++)
        {
            if(it<=m) if(s[i]==t[it]) it++;
            pref[i]=it-1;
            mn[pref[i]]=min(mn[pref[i]],i);
        }
        it=m;
        for(int i=n;i>0;i--)
        {
            if(it>0) if(s[i]==t[it]) it--;
            suf[i]=it+1;
            mx[suf[i]]=max(mx[suf[i]],i);
        }
        int ans=0;
        for(int i=1;i<m;i++) ans=max(ans,mx[i+1]-mn[i]);
        cout<<ans<<endl;
    }

    return 0;
}