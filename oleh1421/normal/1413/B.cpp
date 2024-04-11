#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=510;
int a[N][N];
int b[N][N];
int p[N*N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cin>>a[i][j],p[a[i][j]]=i;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++) cin>>b[i][j];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<a[p[b[1][i]]][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}