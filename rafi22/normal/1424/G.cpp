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

const bool multi=0;

vector <pair<int,bool> > ev;

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
        int n,r,l,ans=0,p=1,act=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>r>>l;
            ev.pb({l,0});
            ev.pb({r,1});
        }
        ev.pb({inf,0});
        sort(ev.begin(),ev.end());
        for(int i=0;i<2*n;i++)
        {
            if(ev[i].nd) act++;
            else act--;
            if(ev[i+1].st!=ev[i].st)
            {
                if(act>ans)
                {
                    p=ev[i].st;
                    ans=act;
                }
            }
        }
        cout<<p<<" "<<ans;
    }

    return 0;
}