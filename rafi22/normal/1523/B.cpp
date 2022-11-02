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

int a[100007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<pair<int,pair<int,int>>>ans;
        for(int i=1;i<=n;i+=2)
        {
            ans.pb({2,{i,i+1}});
            ans.pb({1,{i,i+1}});
            ans.pb({1,{i,i+1}});
            ans.pb({2,{i,i+1}});
            ans.pb({1,{i,i+1}});
            ans.pb({1,{i,i+1}});
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd.st<<" "<<x.nd.nd<<endl;
    }

    return 0;
}