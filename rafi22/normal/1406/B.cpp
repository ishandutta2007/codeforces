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

int tab[500007];

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
        vector <int> pl,mn;
        int zero=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a==0) zero++;
            else if(a>0) pl.push_back(a);
            else mn.push_back(a);
        }
        sort(pl.begin(),pl.end(),greater<int>());
        sort(mn.begin(),mn.end(),greater<int>());
        int ans=-inf;
        if(pl.size()>=3&&mn.size()>=2)
        {
            ans=max(ans,pl[0]*pl[1]*pl[2]*mn[mn.size()-1]*mn[mn.size()-2]);
            //cout<<1<<ans<<endl;
        }
        if(zero) ans=max(ans,(int)0);
        if(pl.size()>=2&&mn.size()>=3)
        {
            ans=max(ans,pl[0]*pl[1]*mn[0]*mn[1]*mn[2]);
            //cout<<2<<ans<<endl;
        }
        if(pl.size()>=1&&mn.size()>=4)
        {
            ans=max(ans,pl[0]*mn[mn.size()-1]*mn[mn.size()-2]*mn[mn.size()-3]*mn[mn.size()-4]);
            //cout<<3<<ans<<endl;
        }
        if(pl.size()>=0&&mn.size()>=5)
        {
            ans=max(ans,mn[0]*mn[1]*mn[2]*mn[3]*mn[4]);
            //cout<<4<<ans<<endl;
        }
        if(pl.size()>=4&&mn.size()>=1)
        {
            ans=max(ans,pl[0]*pl[1]*pl[2]*pl[3]*mn[0]);
            //cout<<5<<ans<<endl;
        }
        if(pl.size()>=5&&mn.size()>=0)
        {
            ans=max(ans,pl[0]*pl[1]*pl[2]*pl[3]*pl[4]);
            //cout<<6<<ans<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}