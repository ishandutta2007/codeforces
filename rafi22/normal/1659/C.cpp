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

int x[200007];

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
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++) cin>>x[i];
        int ans=inf,act=x[n]*b;
        for(int i=n;i>0;i--)
        {
            ans=min(ans,act+x[i-1]*a);
            if(i>1) act+=(n-i+1)*(x[i-1]-x[i-2])*b;
        }
        cout<<ans<<endl;
    }

    return 0;
}