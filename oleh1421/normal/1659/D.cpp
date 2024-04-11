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
int c[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i],a[i]=1;
    for (int i=1;i<=n;i++){
        if (c[i]==0) a[i]=0;
        else {
            if (a[i]==0) c[i]+=(i-1);
            a[c[i]+1]=0;
        }
    }
//    (n-c[1]+1)
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
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