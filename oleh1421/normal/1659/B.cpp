//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=500010;
const int K=155;
const ll inf=1000000000000000001;
const ll mod=998244353;
int a[N];
int f[N];
//int b[N];
//ll dp[N][N*2][K][2];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        f[i]=0;
        char c;cin>>c;
        a[i]=(c-'0');
        if (k%2) a[i]^=1;
    }
    for (int i=1;i<=n;i++){
        if (k==0) break;
        if (a[i]==0){
            f[i]++;
            a[i]^=1;
            k--;
        }
    }
    f[n]+=k;
    if (k%2) a[n]^=1;
    for (int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
    for (int i=1;i<=n;i++) cout<<f[i]<<" ";
    cout<<endl;



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
4 0
0 0 0 1

**/