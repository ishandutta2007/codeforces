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

const bool multi=0;

int a[5007];
int b[5007];
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
        int n,ans=0,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) sum+=a[i]*b[i];
        ans=sum;
        for(int i=1;i<=n;i++)
        {
            int act=sum;
            for(int j=1;j<=n;j++)
            {
                if(i-j<=0||i+j>n) break;
                act-=a[i-j]*b[i-j];
                act+=a[i+j]*b[i-j];
                act-=a[i+j]*b[i+j];
                act+=a[i-j]*b[i+j];
                ans=max(ans,act);
            }
        }
        for(int i=1;i<=n;i++)
        {
            int act=sum;
            for(int j=1;j<=n;j++)
            {
                if(i-j+1<=0||i+j>n) break;
                act-=a[i-j+1]*b[i-j+1];
                act+=a[i+j]*b[i-j+1];
                act-=a[i+j]*b[i+j];
                act+=a[i-j+1]*b[i+j];
                ans=max(ans,act);
            }
        }
        cout<<ans;
    }

    return 0;
}