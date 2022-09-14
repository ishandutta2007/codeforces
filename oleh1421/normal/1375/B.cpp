//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=1010;
int need[N][N];
int a[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            need[i][j]=4;
        }
    }
    for (int i=1;i<=n;i++){
        need[i][1]--;
        need[i][m]--;
    }
    for (int i=1;i<=m;i++){
        need[1][i]--;
        need[n][i]--;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]>need[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<need[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}