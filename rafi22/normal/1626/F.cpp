#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

//#define int long long
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

const bool multi=0;

const int L=12252240/17;

ll p[20];

int DP[13000000];

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
        mod=mod1;
        ll n,a,x,y,k,M,S=0,ans=0;
        cin>>n>>a>>x>>y>>k>>M;
        p[0]=1;
        for(int i=1;i<=k;i++) p[i]=p[i-1]*n%mod;
        for(int i=0;i<n;i++)
        {
            DP[a%L]++;
            S=(S+(a-a%L))%mod;
            a=(a*x+y)%M;
        }
        ans=k*S%mod*p[k-1]%mod;
        for(int i=1;i<=k;i++)
        {
            for(int j=0;j<L;j++)
            {
                if(!DP[j]) continue;
                ans=(ans+j*(ll)DP[j]%mod*p[k-i])%mod;
                if(i!=k)
                {
                    int x=DP[j];
                    DP[j]=(ll)DP[j]*(n-1)%mod;
                    int c=j%i;
                    DP[j-c]+=x;
                    if(DP[j-c]>=mod) DP[j-c]-=mod;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}