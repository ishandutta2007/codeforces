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

int a[100007];
int p[100007];
double d[100007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i]>>d[i];
        int it=n;
        while(it&&a[it]==it) it--;
        double ans=0;
        if(it==0) ans=1;
        else
        {
            double xd=1;
            for(int i=1;i<=m;i++)
            {
                if(p[i]>=it) xd*=(1-d[i]);
            }
            ans=1-xd;
        }
        cout<<fixed<<setprecision(8)<<ans<<endl;
    }

    return 0;
}