//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=1010;
const int L=20;
const ll mod=1000000007;
const int inf=1e9;
int a[N][N];
int f[N][N];
void solve(int Case){
    int n,m;cin>>n>>m;
    int mnx=inf,mny=inf,mxx=-inf,mxy=-inf;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='B');
            if (a[i][j]){
                int x=i-j;
                int y=i+j;
                mnx=min(mnx,x);
                mxx=max(mxx,x);
                mny=min(mny,y);
                mxy=max(mxy,y);
            }
        }
    }
    int mn=inf;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x=i-j;
            int y=i+j;
            f[i][j]=max({x-mnx,mxx-x,y-mny,mxy-y});
//            cout<<f[i][j]<<" ";
            mn=min(mn,f[i][j]);
        }
//        cout<<endl;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (f[i][j]==mn){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/