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
int DP[200007];
map<int,int>cnt;

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
        cnt.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        DP[0]=1;
        int ans=1,sum=0;
        cnt[0]=1;
        for(int i=1;i<=n;i++)
        {
            DP[i]=(ans-cnt[sum]+mod)%mod;
            cnt[sum]=(cnt[sum]+DP[i])%mod;
            sum+=a[i];
            ans=(ans+DP[i])%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}