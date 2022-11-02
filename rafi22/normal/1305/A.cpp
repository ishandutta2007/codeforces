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
        int n,x;
        cin>>n;
        vector<int>a,b;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            a.pb(x);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            b.pb(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(auto x:a) cout<<x<<" ";
        cout<<endl;
        for(auto x:b) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}