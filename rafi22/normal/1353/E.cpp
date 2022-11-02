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

int DP[1000007];
int pref[1000007];

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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1];
            if(s[i]=='1') pref[i]++;
        }
        int ans=pref[n];
        for(int i=1;i<=n;i++)
        {
            DP[i]=(s[i]=='0')+min(DP[max(0LL,i-k)],pref[max(0LL,i-k)]-pref[0])+pref[i-1]-pref[max(0LL,i-k)];
            ans=min(ans,DP[i]+pref[n]-pref[i]);
           // cout<<DP[i]<<" ";
        }
      //  cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}