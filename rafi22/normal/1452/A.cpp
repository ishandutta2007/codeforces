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
        int x,y,ans=0;
        cin>>x>>y;
        int z=min(x,y);
        ans+=2*z;
        x-=z;
        y-=z;
        if(x>0)
        {
            ans+=1+2*(x-1);
        }
        if(y>0)
        {
            ans+=1+2*(y-1);
        }
        cout<<ans<<endl;
    }

    return 0;
}