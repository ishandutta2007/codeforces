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

bool is[1000007];

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
        int n,x,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            is[x]=1;
        }
        for(int i=1000000;i>0;i--)
        {
            int g=0;
            for(int j=2*i;j<=1000000;j+=i)
            {
                if(!is[j]) continue;
                if(!g) g=j/i;
                else
                {
                    g=__gcd(g,j/i);
                    if(g==1)
                    {
                        is[i]=1;
                        break;
                    }
                }
            }
            ans+=is[i];
        }
        cout<<ans-n;
    }

    return 0;
}