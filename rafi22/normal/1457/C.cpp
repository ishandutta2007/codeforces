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

int DP[200007];

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
       int n,p,k,x,y,ans=inf;
       cin>>n>>p>>k;
       string str;
       cin>>str;
       cin>>x>>y;
       str='#'+str;
       for(int i=n;i>0;i--)
       {
           if(str[i]=='1') DP[i]=DP[i+k];
           else DP[i]=DP[i+k]+x;
       }
       for(int i=p;i<=n;i++) ans=min(ans,DP[i]+(i-p)*y);
       cout<<ans<<endl;
       for(int i=1;i<=n;i++) DP[i]=0;
    }

    return 0;
}