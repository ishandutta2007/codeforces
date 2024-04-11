#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

int a[1007];

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
        for(int i=1;i<=n;i+=2)
        {
            int mn=0,act=0;
            for(int j=i+1;j<=n;j+=2)
            {
                int L=1,R=a[i];
                R=min(R,a[j]-act);
                L=max(L,-act+1);
                L=max(L,-mn);
                ans+=max(0LL,(R-L+1));
                act-=a[j];
                mn=min(mn,act);
                act+=a[j+1];
            }
        }
        cout<<ans;
    }

    return 0;
}