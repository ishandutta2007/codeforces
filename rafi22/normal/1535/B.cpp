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

int a[2007];

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
        int n,x,ans=0;
        cin>>n;
        vector<int>v[2];
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            v[x%2].pb(x);
        }
        int it=0;
        for(auto x:v[0]) a[++it]=x;
        for(auto x:v[1]) a[++it]=x;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(__gcd(a[j],2*a[i])>1) ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}