#include <bits/stdc++.h>

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

ll DP[20000007];
int ile[20000007];

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
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            for(int j=1;j*j<=x;j++)
            {
                if(x%j==0)
                {
                    ile[j]++;
                    if(x/j!=j) ile[x/j]++;
                }
            }
        }
        ll ans=0;
        for(int i=20000000;i>0;i--)
        {
            if(!ile[i]) continue;
            for(int j=2*i;j<=20000000;j+=i)
            {
                if(!ile[j]) continue;
                DP[i]=max(DP[i],DP[j]+(ll)(ile[i]-ile[j])*(ll)i);
            }
            DP[i]=max(DP[i],ile[i]*(ll)i);
            ans=max(ans,DP[i]);
        }
        cout<<ans;
    }

    return 0;
}