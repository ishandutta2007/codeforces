#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[200007],b[200007];

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
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        int l=1,r=n,ans=0,sr;
        while(l<=r)
        {
            sr=(l+r)/2;
            int act=0;
            for(int i=1;i<=n;i++)
            {
                if(act>b[i]) continue;
                if(act+1+a[i]>=sr) act++;
            }
            if(act>=sr)
            {
                ans=sr;
                l=sr+1;
            }
            else r=sr-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}