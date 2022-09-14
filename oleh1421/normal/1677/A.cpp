#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=5010;
const ll mod=1000000007;
int p[N];
int add[N][N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++){
        add[i][0]=0;
        for (int j=1;j<=n;j++){
            add[i][j]=(add[i][j-1]+(p[j]<p[i]));
        }
    }
    ll res=0ll;
    for (int b=1;b<=n;b++){
        for (int c=b+1;c<=n;c++){
            int cur=add[c][b-1]*(p[b]-1-add[b][c]);
            res+=cur;
        }
    }
    cout<<res<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/