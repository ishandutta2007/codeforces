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
        int n;
        cin>>n;
        if(n==2)
        {
            cout<<1<<endl<<1<<endl;
            return 0;
        }
        vector<int>ans;
        int xd=1;
        for(int i=1;i<n;i++)
        {
            if(__gcd(i,n)==1)
            {
                if((i==n-1&&xd!=1)||i!=n-1)
                {
                    ans.pb(i);
                    xd=xd*i%n;
                }
            }
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}