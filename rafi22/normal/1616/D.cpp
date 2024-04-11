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

int a[100007];
int P[100007];

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
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>x;
        for(int i=1;i<=n;i++) a[i]-=x;
        int mx=-inf;
        int ans=0;
        int last=0;
        for(int i=1;i<=n;i++)
        {
            if(i-2>=last) mx=max(mx,P[i-2]);
            P[i]=P[i-1]+a[i];
            if(P[i]<mx)
            {
                ans++;
                mx=-inf;
                last=i;
            }
        }
        cout<<n-ans<<endl;
    }

    return 0;
}