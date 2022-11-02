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

int d[100007];

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
        int n,ans=0,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>d[i];
        sort(d+1,d+n+1);
        for(int i=1;i<=n;i++)
        {
            ans-=(i-1)*d[i]-sum;
            sum+=d[i];
        }
        ans+=d[n];
        cout<<ans<<endl;
    }

    return 0;
}