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

int tab[300007];
int pref[300007];

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
        int n,k,z,ans;
        cin>>n>>k>>z;
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
            pref[i]=pref[i-1]+tab[i];
        }
        ans=pref[k+1];
        for(int i=1;i<=k;i++)
        {
            int k1=k-i+1;
            for(int j=0;j<=z;j++)
            {
                ans=max(ans,pref[i]+min(j,k1/2)*(tab[i]+tab[i+1])+pref[i+k1-2*min(j,k1/2)]-pref[i]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}