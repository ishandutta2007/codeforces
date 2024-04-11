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

int a[3507];

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
        int n,m,k,ans=0;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        k=min(k,m-1);
        for(int i=0;i<=k;i++)
        {
            int act=inf;
            for(int j=0;j<=m-1-k;j++)
            {
                act=min(act,max(a[i+j+1],a[n-(k-i)-(m-1-k-j)]));
            }
            ans=max(ans,act);
        }
        cout<<ans<<endl;
    }

    return 0;
}