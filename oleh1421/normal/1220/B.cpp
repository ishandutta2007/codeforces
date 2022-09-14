#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int a[2001][2001];
int b[2001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin>>a[i][j];
    int cur=((a[1][2]*a[1][3])/a[3][2]);
    int l=1ll;
    int r=1000000001ll;
    while (r-l>1){
        int m=(l+r)/2ll;
        if (m*m<=cur) l=m;
        else r=m;
    }
    ll x=l;
    cout<<x<<" ";
    for (int i=2;i<=n;i++) cout<<a[1][i]/x<<" ";
    return 0;
}