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
        int n,m,ans=0,ans1=0,sum=0,sum1=0,a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            sum+=a;
            ans=max(ans,sum);
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a;
            sum1+=a;
            ans1=max(ans1,sum1);
        }
        cout<<ans+ans1<<endl;
    }

    return 0;
}