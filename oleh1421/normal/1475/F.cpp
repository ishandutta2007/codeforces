//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1010;
int a[N][N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            a[i][j]=c-'0';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            a[i][j]^=c-'0';
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            if ((a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1])%2){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";



}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*
1
4 5
3 2 1 2
2 1 2 1
*/