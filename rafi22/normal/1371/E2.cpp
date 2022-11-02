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

int a[100007];
int pref[100007];
bool bad[100007];

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
        int n,k,mx=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        sort(a+1,a+n+1);
        int it=1;
        mx-=n-1;
        for(int i=0;i<n;i++)
        {
            if(i!=0) pref[i]=pref[i-1];
            while(it<=n&&a[it]<=mx)
            {
                it++;
                pref[i]++;
            }
            mx++;
        }
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            bad[((i-pref[i])%k+k)%k]=1;
         //   cout<<((i-pref[i])%k+k)%k<<" "<<pref[i]<<endl;
            if(!bad[i%k]&&i<k) ans.pb(mx-n+i);
        }
        reverse(ans.begin(),ans.end());
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x<<" ";
    }

    return 0;
}