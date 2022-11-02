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

bool odw[400007];

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
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            odw[a]=1;
        }
        int ans=n+1,mx=0,act=0;
        for(int i=1;i<=2*n;i++)
        {
            if(odw[i]) act++;
            else act--;
            mx=max(mx,act);
        }
        ans-=mx;
        mx=0,act=0;
        for(int i=2*n;i>0;i--)
        {
            if(odw[i]) act++;
            else act--;
            mx=max(mx,act);
        }
        ans-=mx;
        cout<<ans<<endl;
        for(int i=1;i<=2*n;i++) odw[i]=0;
    }
    return 0;
}