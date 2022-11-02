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

const bool multi=0;

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
        int n,d,m,a,ans=0,sum=0,sum1=0,it=0;
        cin>>n>>d>>m;
        vector<int>v1,v2;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a<=m)
            {
                v1.pb(a);
                sum1+=a;
            }
            else v2.pb(a);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        for(int i=0;i<=sz(v2);i++)
        {
            if(i*d<sz(v2)-i||(i-1)*d>n-i)
            {
                if(i!=sz(v2)) sum+=v2[i];
                continue;
            }
            while(sz(v2)-i+it<(i-1)*d) sum1-=v1[it++];
           // cout<<i<<" "<<sum<<" "<<sum1<<endl;
            ans=max(ans,sum+sum1);
            if(i!=sz(v2)) sum+=v2[i];
        }
        cout<<ans;
    }

    return 0;
}