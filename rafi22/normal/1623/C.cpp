#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

int h[200007];
int a[200007];

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
        for(int i=1;i<=n;i++) cin>>h[i];
        int l=1,r=1000000003,sr,ans=0;
        while(l<=r)
        {
            sr=(l+r)/2;
            for(int i=1;i<=n;i++) a[i]=h[i];
            bool ok=1;
            for(int i=n;i>2;i--)
            {
                int x=max(0LL,min((a[i]-sr)/3,h[i]/3));
                a[i]-=3*x;
                a[i-1]+=x;
                a[i-2]+=2*x;
            }
            for(int i=1;i<=n;i++) if(a[i]<sr) ok=0;
            if(ok)
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