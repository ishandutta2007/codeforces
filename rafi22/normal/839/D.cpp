#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

const bool multi=0;

int ile[1000007];
int p[200007];

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
        int n,x;
        cin>>n;
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=p[i-1]*2%mod;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            ile[x]++;
        }
        for(int i=1;i<=1000000;i++)
        {
            for(int j=2*i;j<=1000000;j+=i) ile[i]+=ile[j];
        }
        for(int i=1;i<=1000000;i++) ile[i]=p[ile[i]-1]*ile[i]%mod;
        int ans=0;
        for(int i=1000000;i>1;i--)
        {
            for(int j=2*i;j<=1000000;j+=i) ile[i]=(ile[i]-ile[j]+mod)%mod;
            ans=(ans+ile[i]*i)%mod;
        }
        cout<<ans;
    }

    return 0;
}