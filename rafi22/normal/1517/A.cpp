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
        int n;
        cin>>n;
        if(n%2050!=0) cout<<-1<<endl;
        else
        {
            n/=2050;
            int ans=0;
            while(n>0)
            {
                ans+=n%10;
                n/=10;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}