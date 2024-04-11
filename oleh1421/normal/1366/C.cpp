//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=155;
int a[N][N];
int cnt[N+N][2];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<=n+m;i++){
        cnt[i][0]=cnt[i][1]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            cnt[i+j-2][a[i][j]]++;
            cnt[n+m-i-j][a[i][j]]++;
        }
    }
    int tot=0;
    for (int i=0;i+i<n+m-2;i++) {
//        if (i+i==n+m-2) continue;
        tot+=min(cnt[i][0],cnt[i][1]);
    }
    cout<<tot<<endl;

}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/