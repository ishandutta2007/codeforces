#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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
    mod=mod1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,ans=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ans=ans*i%mod;
        }
        sort(a+1,a+n+1);
        if(a[n]>a[n-1]+1) cout<<0<<endl;
        else
        {
            if(a[n]==a[n-1]) cout<<ans<<endl;
            else
            {
                int act=1;
                for(int i=n-2;i>0;i--)
                {
                    if(a[i]!=a[n-1])
                    {
                        for(int j=1;j<=i;j++) act=act*(n-j+1)%mod;
                        break;
                    }
                    act=act*(n-i)%mod;
                }
                cout<<(ans-act+mod)%mod<<endl;
            }
        }
    }

    return 0;
}