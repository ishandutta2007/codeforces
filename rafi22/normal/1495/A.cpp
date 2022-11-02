#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define double long double
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
        int n;
        cin>>n;
        vector<int>v1,v2;
        for(int i=1;i<=2*n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==0) v2.pb(abs(y));
            else v1.pb(abs(x));
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        double ans=0;
        for(int i=0;i<sz(v1);i++)
        {
            //cout<<sqrt(v1[i]*v1[i]+v2[i]*v2[i])<<endl;
            ans+=sqrt((double)(v1[i]*v1[i]+v2[i]*v2[i]));
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;

    }

    return 0;
}