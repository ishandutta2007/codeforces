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
        int n,m,ans=0,a,cnt=0;
        cin>>n>>m;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a;
                if(a<=0)
                {
                    v.pb(a);
                    cnt++;
                }
                else v.pb(-a);
            }
        }
        if(cnt%2==1)
        {
            sort(v.begin(),v.end(),greater<int>());
            ans+=v[0];
            for(int i=1;i<v.size();i++) ans+=abs(v[i]);
        }
        else
        {
            for(int i=0;i<v.size();i++) ans+=abs(v[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}