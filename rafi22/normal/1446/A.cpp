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
        int n,w,a,sum=0;
        cin>>n>>w;
        vector<pair<int,int>>v;
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            v.pb({a,i});
        }
        sort(v.begin(),v.end());
        bool ok=0;
        for(auto x:v)
        {
            sum+=x.st;
            ans.pb(x.nd);
            if(sum>=w/2+w%2)
            {
                if(sum<=w)
                {
                    ok=1;
                    break;
                }
                else
                {
                    if(x.st>=w/2+w%2&&x.st<=w)
                    {
                        ans.clear();
                        ans.pb(x.nd);
                        ok=1;
                        break;
                    }
                }

            }
        }
        if(!ok) cout<<-1<<endl;
        else
        {
            cout<<ans.size()<<endl;
            for(auto x:ans) cout<<x<<" ";
            cout<<endl;
        }

    }

    return 0;
}