//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int ar[N][N];
void solve(){
    int n,m,a,b;cin>>n>>m>>a>>b;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            ar[i][j]=0;
        }
    }
    if (n*a!=m*b){
        cout<<"NO\n";
        return;
    }
    for (int i=0;i<n*a;i++){
        ar[i/a][i%m]=1;
    }
    cout<<"YES\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cout<<ar[i][j];
        cout<<endl;
    }
    cout<<endl;
//    int n;cin>>n;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            char c;cin>>c;
//            a[i][j]=(c-'0');
//        }
//    }
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