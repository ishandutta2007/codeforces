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
        for(int i=1;i<=n;i++) cin>>a[i];
        int mn1=inf,mn2=inf,sum=0,ans=inf;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            if(i%2==1) mn1=min(mn1,a[i]);
            else mn2=min(mn2,a[i]);
            if(i>1) ans=min(ans,sum+(n-i/2-i%2)*mn1+(n-i/2)*mn2);
        }
        cout<<ans<<endl;
    }

    return 0;
}