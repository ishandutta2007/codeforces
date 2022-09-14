#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N=1010;
const int K=510;
const ll mod=998244353;
int a[N][N];
void solve(){
    int n,m,r,c;cin>>n>>m>>r>>c;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='B');
        }
    }
    if (a[r][c]){
        cout<<0<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        if (a[i][c]){
            cout<<1<<endl;
            return;
        }
    }
    for (int i=1;i<=m;i++){
        if (a[r][i]){
            cout<<1<<endl;
            return;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                cout<<2<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;

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
/**
ababababa
2
1 5 c
2 1 7 aba
**/