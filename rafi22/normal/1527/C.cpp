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

pair<int,int> a[200007];

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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].st;
            a[i].nd=i;
        }
        sort(a+1,a+n+1);
        int ans=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].st!=a[i-1].st) sum=0;
            ans+=sum*(n-a[i].nd+1);
            sum+=a[i].nd;
        }
        cout<<ans<<endl;
    }

    return 0;
}