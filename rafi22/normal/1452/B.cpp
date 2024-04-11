#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int n,ans=0,sum=0,mxi=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+n+1);
        ans+=(n-1-sum%(n-1))%(n-1);
        sum+=(n-1-sum%(n-1))%(n-1);
        mxi=max(mxi,(n-1)*a[n-1]-sum);
        for(int i=1;i<=n;i++)
        {
            mxi=max(mxi,(n-1)*a[n]-sum);
        }
        cout<<ans+mxi<<endl;
    }

    return 0;
}