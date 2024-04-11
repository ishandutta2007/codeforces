#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
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
        int b,q,y;
        cin>>b>>q>>y;
        int c,r,z;
        cin>>c>>r>>z;
        bool ok=1,in=0;
        int ans=0;
        if(r%q!=0||c<b||(c-b)%q!=0) ok=0;
        int x=(c-b)/q;
        if(b+q*(y-1)<c+r*(z-1)) ok=0;
        set<int>D;
        for(int i=1;i<=sqrt(r)+2;i++)
        {
            if(r%i==0)
            {
                D.insert(i);
                D.insert(r/i);
            }
        }
        for(auto p:D)
        {
            if(p*q/__gcd(p,q)!=r) continue;
            if(x*q<r||(y-1-(x+z*(r/q)-1))*q<r) in=1;
            ans=(ans+(r/p)*(r/p))%mod;
        }
        if(!ok) cout<<0<<endl;
        else if(in) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}