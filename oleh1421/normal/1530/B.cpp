//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=1010;
int a[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=0;
    a[1][1]=a[n][m]=a[1][m]=a[n][1]=1;
    for (int i=2;i<n;i++){
        if (!a[i-1][1] && !a[i+1][1]) a[i][1]=1;
        if (!a[i-1][m] && !a[i+1][m]) a[i][m]=1;
    }
    for (int i=2;i<m;i++){
        if (!a[1][i-1] && !a[1][i+1]) a[1][i]=1;
        if (!a[n][i-1] && !a[n][i+1]) a[n][i]=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
5
6 9 1 9 6
**/