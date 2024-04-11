#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=310;
const ll mod=998244353;
pair<int,int> a[N*N];
int t[N];
int s[N*N];
int x[N][N];
int y[N][N];
int val[N*N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i].first,a[i].second=i,val[i]=a[i].first;
    sort(a+1,a+n*m+1);
    for (int i=1;i<=n*m;i++) {
//        cout<<a[i].second<<endl;
        s[a[i].second]=i;
    }
    for (int i=1;i<=n*m;i++){
        int r=(s[i]-1)/m+1;
        int c=s[i]-(r-1)*m;
        x[r][c]=i;
        y[r][c]=val[i];
    }
    int res=0;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++) cout<<y[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int t=j+1;t<=m;t++){
                if (x[i][j]<x[i][t] && y[i][j]!=y[i][t]) {
                    res++;
//                    cout<<i<<" "<<j<<" "<<t<<endl;
                }
            }
        }
    }

    cout<<res<<endl;


}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}