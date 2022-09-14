//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
#define int ll
const int inf=1000000001;
int n[4],m[4];
int a[4][N];
vector<int>g[4][N];
int dp[4][N];
void solve(){
    for (int i=0;i<4;i++) cin>>n[i];
    for (int i=0;i<4;i++){
        for (int j=1;j<=n[i];j++) cin>>a[i][j];
    }
    for (int i=1;i<=3;i++){
        cin>>m[i];
        for (int j=1;j<=m[i];j++){
            int a,b;cin>>a>>b;
            g[i][b].push_back(a);
        }
    }
    for (int i=1;i<=n[0];i++) dp[0][i]=a[0][i];
    for (int i=1;i<4;i++){
        set<pair<int,int> >st;
        for (int j=1;j<=n[i-1];j++) st.insert({dp[i-1][j],j});
        for (int j=1;j<=n[i];j++){
            for (int to:g[i][j]){
                st.erase({dp[i-1][to],to});
            }
            if (st.empty()) dp[i][j]=inf;
            else dp[i][j]=a[i][j]+(*st.begin()).first;
            for (int to:g[i][j]){
                st.insert({dp[i-1][to],to});
            }
        }
    }
    ll res=inf;
    for (int i=1;i<=n[3];i++) res=min(res,dp[3][i]);
    if (res==inf) res=-1;
    cout<<res<<endl;



}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1 2 3 1 2 3
3 2 1 3 2 1
1 2 4 5 2 3 5 1 2 3 4 5
5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
**/
//30
//9 10
//x(x+1)/(2*n)
///6778 5734
/*
11*x 13*a
11*y 13*b
*/
//11 14641 28561 13