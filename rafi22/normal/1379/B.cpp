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
        int l,r,m,x;
        cin>>l>>r>>m;
        for(int i=l;i<=r;i++)
        {
            x=m-m%i;
            if(x!=0&&m-x<=r-l)
            {
                cout<<i<<" "<<r<<" "<<r-(m-x)<<endl;
                break;
            }
            x+=i;
            if(x-m<=r-l)
            {
                cout<<i<<" "<<r-(x-m)<<" "<<r<<endl;
                break;
            }
        }
    }

    return 0;
}