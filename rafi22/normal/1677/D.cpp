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

int a[1000007];

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
        int n,k;
        cin>>n>>k;
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>0&&i+k>n) ans=0;
        }
        for(int i=n;i>0;i--)
        {
            if(i>k)
            {
                if(a[i-k]==-1) ans=ans*i%mod;
                if(a[i-k]==0) ans=ans*(k+1)%mod;
            }
            else ans=ans*i%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}