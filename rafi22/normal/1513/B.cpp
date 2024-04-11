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
        int n,mn=inf,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<mn)
            {
                mn=a[i];
                cnt=1;
            }
            else if(a[i]==mn) cnt++;
        }
        bool ok=1;
        for(int i=1;i<=n;i++) if((a[i]&mn)!=mn) ok=0;
      //  cout<<ok<<endl;
        if(!ok) cout<<0<<endl;
        else
        {
            int ans=cnt*(cnt-1)%mod;
            for(int i=1;i<=n-2;i++) ans=ans*i%mod;
            cout<<ans<<endl;
        }
    }

    return 0;
}