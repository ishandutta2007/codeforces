#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int n,ans=0,m=1;
        cin>>n;
        while(n>0)
        {
            //cout<<n<<endl;
            if(n%2==1)
            {
                if(m%2==1)
                    ans++;
                n--;
            }
            else
            {
                if(n!=4&&((n-2)/2)%2==1)
                {
                    if(m%2==1)
                        ans++;
                    n--;
                }
                else
                {
                    if(m%2==1)
                    ans+=n/2;
                    n/=2;
                }
            }
            m++;
        }
        cout<<ans<<endl;
    }

    return 0;
}