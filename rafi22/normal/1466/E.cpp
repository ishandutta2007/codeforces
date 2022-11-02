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

int a[500007];
int bit[61];

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
        int n,ans=0;
        cin>>n;
        for(int i=0;i<=60;i++) bit[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            for(int j=0;j<=60;j++)
            {
                if((a[i]&(1LL<<j))) bit[j]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int andS=0,orS=0;
            for(int j=0;j<=60;j++)
            {
                int pot=(1LL<<j)%mod;
                if((a[i]&(1LL<<j)))
                {
                    andS=(andS+bit[j]*pot)%mod;
                    orS=(orS+n*pot)%mod;
                }
                else
                {
                    orS=(orS+bit[j]*pot)%mod;
                }
            }
            ans=(ans+andS*orS)%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}