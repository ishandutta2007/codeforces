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

bool good(int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        for(int j=i+1;j<=r;j++)
        {
            for(int k=j+1;k<=r;k++)
            {
                if(a[i]>=a[j]&&a[j]>=a[k]) return 0;
                if(a[i]<=a[j]&&a[j]<=a[k]) return 0;
            }
        }
    }
    return 1;
}

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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=min(n,i+10);j++) ans+=good(i,j);
        }
        cout<<ans<<endl;
    }

    return 0;
}