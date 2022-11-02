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

pair<int,int>x[200007];
int a[200007];
int b[200007];

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
        int n,sum=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        vector<pair<pair<int,int>,int>>vec;
        for(int i=1;i<=n;i++)
        {
            sum+=abs(a[i]-b[i]);
            if(a[i]>b[i]) vec.pb({{b[i],a[i]},0});
            else vec.pb({{a[i],b[i]},1});
        }
        sort(vec.begin(),vec.end());
        int mx0=0,mx1=0;
        for(auto x:vec)
        {
            if(x.nd)
            {
                ans=max(ans,min(x.st.nd,mx0)-x.st.st);
                mx1=max(mx1,x.st.nd);
            }
            else
            {
                ans=max(ans,min(x.st.nd,mx1)-x.st.st);
                mx0=max(mx0,x.st.nd);
            }
        }
        cout<<sum-2*ans<<endl;
    }

    return 0;
}