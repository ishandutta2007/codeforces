//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=1010;
int a[N][N];
int row[N];
int col[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<=n;i++) row[i]=0;
    for (int i=0;i<=m;i++) col[i]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    }
    int cntR=0;
    int cntC=0;
    for (int i=1;i<=n;i++){
        if (!row[i]) cntR++;
    }
    for (int i=1;i<=m;i++){
        if (!col[i]) cntC++;
    }
    if (min(cntC,cntR)%2) cout<<"Ashish\n";
    else cout<<"Vivek\n";
}
int main()
{

//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}