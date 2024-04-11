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

int a[5007];
int sub[5007];

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
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=max(0LL,a[i]-sub[i]-1);
            for(int j=i+2;j<=min(n,i+a[i]);j++) sub[j]++;
            sub[i+1]+=max(0LL,sub[i]-a[i]+1);
        }
        for(int i=0;i<=n+5;i++) sub[i]=0;
        cout<<ans<<endl;
    }

    return 0;
}