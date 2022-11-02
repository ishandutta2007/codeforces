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

int mx[5007];
int a[5007];
int ans[5007];

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
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mx[i]=-inf;
        }
        for(int i=1;i<=n;i++)
        {
            int s=0;
            for(int j=i;j<=n;j++)
            {
                s+=a[j];
                mx[j-i+1]=max(mx[j-i+1],s);
            }
        }
        int C=-inf;
        for(int i=n;i>=0;i--)
        {
            C=max(C,mx[i]);
            ans[i]=C+i*x;
        }
        for(int i=1;i<=n;i++) ans[i]=max(ans[i-1],ans[i]);
        for(int i=0;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}