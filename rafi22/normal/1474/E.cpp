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
        vector<int>p;
        if(n%2)
        {
            p.pb(n/2+2);
            for(int i=1;i<=n;i++) if(i!=n/2+2&&i!=n/2+1) p.pb(i);
            p.pb(n/2+1);
        }
        else
        {
            p.pb(n/2+1);
            for(int i=1;i<=n;i++) if(i!=n/2+1&&i!=n/2) p.pb(i);
            p.pb(n/2);
        }
        vector<pair<int,int>>a;
        for(int i=n/2+n%2;i>1;i--) a.pb({i,n});
        for(int i=n/2+n%2+1;i<=n;i++) a.pb({i,1});
        int ans=0;
        for(auto x:a) ans+=(x.st-x.nd)*(x.st-x.nd);
        cout<<ans<<endl;
        for(auto x:p) cout<<x<<" ";
        cout<<endl;
        cout<<n-1<<endl;
        for(auto x:a) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}