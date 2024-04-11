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

int msb(int n)
{
    return 64-__builtin_clzll(n)-1;
}
int DP[200007];

vector<int>V[200007];
set<int>S;

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
        int n,x,p;
        cin>>n>>p;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            V[msb(x)].pb(x);
            S.insert(x);
        }
        int ans=0;
        for(int i=0;i<p;i++)
        {
            if(i>0) DP[i]=DP[i-1];
            if(i>1) DP[i]=(DP[i]+DP[i-2])%mod;
            for(auto x:V[i])
            {
                bool ok=1;
                int ile=0;
                int y=x;
                for(int j=0;j<=i;j++)
                {
                    if((x&(1LL<<j)))
                    {
                        if(ile%2==1) break;
                        ile=0;
                    }
                    else ile++;
                    y/=2;
                    if(ile%2==0&&S.count(y))
                    {
                        ok=0;
                        break;
                    }
                }
                DP[i]=(DP[i]+ok)%mod;
            }
            ans=(ans+DP[i])%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}