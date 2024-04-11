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

int a[400007];

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
        a[n+1]=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=0;i<=n;i++) ans+=abs(a[i]-a[i+1]);
        for(int i=1;i<=n;i++) if(a[i]>a[i+1]&&a[i]>a[i-1]) ans-=a[i]-max(a[i-1],a[i+1]);
        cout<<ans<<endl;
    }

    return 0;
}