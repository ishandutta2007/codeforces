#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
int a[111];
int b[111];
int c[111][111];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    int xr1=0;
    int xr2=0;
    for (int i=1;i<=n;i++) xr1^=a[i];
    for (int i=1;i<=m;i++) xr2^=b[i];
    if (xr1!=xr2){
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<n;i++){
        c[i][m]=a[i];
    }
    for (int i=1;i<m;i++){
        c[n][i]=b[i];
    }
    c[n][m]=xr1^a[n]^b[m];
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<c[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
//2 6 -2 -6  2