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

int a[1007];

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
        int n,k,sum=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++)
        {
            int x=min(a[i],k);
            a[n]+=x;
            a[i]-=x;
            k-=x;
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}