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

int a[27];
int b[27];
int c[27];

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
        memset(b,0,sizeof b);
        int n,sum=0,S=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            int x=a[i];
            while(x%2==0)
            {
                b[i]++;
                x/=2;
            }
            sum+=b[i];
            c[i]=x;
            S+=c[i];
        }
        int ans=-inf;
        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            for(int j=0;j<sum-b[i];j++) x*=2;
            ans=max(ans,x+S-c[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}