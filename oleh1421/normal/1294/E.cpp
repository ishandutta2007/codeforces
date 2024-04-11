#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int f[200011];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<vector<int> >a(n);
    for (int i=0;i<n;i++) a[i].resize(m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++) f[j]=n;
        for (int j=0;j<n;j++){
            if (a[j][i]%m!=(i+1)%m || (a[j][i]-i-1)/m>=n) continue;
            f[(j-(a[j][i]-i-1)/m+n)%n]--;;
        }
        int minx=n;
        for (int j=0;j<n;j++){
            minx=min(minx,f[j]+j);
        }
        sum+=minx;
    }
    cout<<sum;
    return 0;
}
//0 0 1