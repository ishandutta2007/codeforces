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

int cnt1[200007];
int cnt2[200007];
int pa[200007];
int pb[200007];

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
        int a,b,k,ans=0;
        cin>>a>>b>>k;
        for(int i=1;i<=k;i++) cin>>pa[i];
        for(int i=1;i<=k;i++) cin>>pb[i];
        for(int i=1;i<=k;i++)
        {
            ans+=i-1-cnt1[pa[i]]-cnt2[pb[i]];
            cnt1[pa[i]]++;
            cnt2[pb[i]]++;
        }
        cout<<ans<<endl;
        for(int i=1;i<=max(a,b);i++)
        {
            cnt1[i]=0;
            cnt2[i]=0;
        }

    }

    return 0;
}