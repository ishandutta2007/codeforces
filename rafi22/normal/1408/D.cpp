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

const bool multi=0;

int tab[1000007];
int a[2007];
int b[2007];
int c[2007];
int d[2007];

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
        int n,m,ans=inf;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        for(int i=1;i<=m;i++) cin>>c[i]>>d[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[j]-a[i]>=0) tab[c[j]-a[i]]=max(tab[c[j]-a[i]],d[j]-b[i]+1);
            }
        }
        int maxi=0;
        for(int i=1000000;i>=0;i--)
        {
            maxi=max(maxi,tab[i]);
            ans=min(ans,i+maxi);
        }
        cout<<ans;
    }

    return 0;
}