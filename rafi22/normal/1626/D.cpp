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

int a[200007];
int ile[200007];

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
        a[n+1]=0;
        sort(a+1,a+n+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=18;j++)
            {
                if((1<<j)>=i)
                {
                    ile[i]=(1<<j)-i;
                    break;
                }
            }
        }
        int mn=inf;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i+1]) continue;
            mn=min(mn,ile[n-i]+ile[i]);
        }
     //   cout<<mn<<endl;
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            mn++;
            for(int j=0;j<=18;j++)
            {
                if(i+(1<<j)<=n&&a[i+(1<<j)]!=a[i+(1<<j)+1])
                {
                    mn=min(mn,ile[n-i-(1<<j)]);
                }
            }
            if(a[i]!=a[i+1]) ans=min(ans,ile[i]+mn);
        }
        cout<<ans<<endl;
    }

    return 0;
}