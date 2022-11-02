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

const bool multi=0;

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
        int n,p,ans=-1;
        cin>>n>>p;
        for(int i=0;i<=31;i++)
        {
            if(n-i*p>0&&__builtin_popcountll(n-i*p)<=i&&i<=n-i*p)
            {
                ans=i;
                break;
            }
        }
        cout<<ans;
    }

    return 0;
}