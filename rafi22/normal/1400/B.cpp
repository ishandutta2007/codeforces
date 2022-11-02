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
        int p,f,cs,cw,s,w,ans=0;
        cin>>p>>f>>cs>>cw>>s>>w;
        for(int i=0;i<=cs;i++)
        {
            if(i*s>p) continue;
            int j=min(cw,(p-i*s)/w);
            int k,l;
            if(s<=w)
            {
                k=min(cs-i,f/s);
                l=min(cw-j,(f-k*s)/w);
            }
            else
            {
                k=min(cw-j,f/w);
                l=min(cs-i,(f-k*w)/s);
            }
            ans=max(ans,i+j+k+l);
        }
        cout<<ans<<endl;
    }
    return 0;
}