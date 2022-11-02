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

int a[200007];
int b[200007];
map<int,int>last;
int p[200007];


void gg()
{
    cout<<0;
    exit(0);
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
        mod=mod1;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            last[a[i]]=i;
        }
        for(int i=1;i<=m;i++) cin>>b[i];
        if(m>n) gg();
        for(int i=1;i<=m;i++)
        {
            p[i]=last[b[i]];
            if(p[i]==0) gg();
            if(p[i]<p[i-1]) gg();
        }
        int ans=1;
        for(int i=1;i<p[1];i++) if(a[i]<b[1]) gg();
        for(int i=2;i<=m;i++)
        {
            int mn=inf;
            for(int j=p[i-1]+1;j<p[i];j++) mn=min(mn,a[j]);
            if(mn<b[i-1]) gg();
            int c=1;
            for(int j=p[i]-1;j>p[i-1];j--)
            {
                if(a[j]<b[i]) break;
                c++;
            }
            ans=ans*c%mod;
        }
        for(int i=p[m]+1;i<=n;i++) if(a[i]<b[m]) gg();
        cout<<ans;
    }

    return 0;
}