#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=510;
int a[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='.');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) a[i][j]+=a[i][j-1];
    }
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=1;k<=n-i+1 && k<=j && k<=m+1-j;k++){
                if (a[i+k-1][j+k-1]!=a[i+k-1][j-k]) {
                    break;
                }
                res++;
            }
        }
    }
    cout<<res<<endl;

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