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

bool p[50007];
vector<int>pr;

signed main()
{
    for(int i=2;i<=50000;i++)
    {
        if(!p[i])
        {
            pr.pb(i);
            for(int j=2*i;j<=50000;j+=i)
            {
                p[j]=1;
            }
        }
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int d;
        cin>>d;
        int kon=0,ans=inf;
        for(int i=0;i<sz(pr);i++)
        {
            while(kon<sz(pr)&&pr[kon]<pr[i]+d) kon++;
            if(kon>=sz(pr)) break;
           // cout<<pr[i]<<" "<<pr[kon]<<endl;
            if(pr[i]-1>=d)ans=min(ans,pr[i]*pr[kon]);
        }
        cout<<ans<<endl;
    }

    return 0;
}