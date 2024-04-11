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

int l[200007];
int r[200007];
int x[200007];
int d[200007];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>x[i];
        int ans=0;
        for(int j=0;j<30;j++)
        {
            for(int i=1;i<=n;i++) d[i]=0;
            for(int i=1;i<=m;i++)
            {
                if(((x[i]&(1<<j)))) continue;
                d[l[i]]++;
                d[r[i]+1]--;
            }
            int s=0,c0=1,c1=0;
            for(int i=1;i<=n;i++)
            {
                s+=d[i];
                if(!s)
                {
                    int x=(c0+c1)%mod;
                    c1=x;
                    c0=x;
                }
                else
                {
                    c0=c0*2%mod;
                    c1=c1*2%mod;
                }
            }
            ans=(ans+c1*(1<<j))%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}