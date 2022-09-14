//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> line;
#define endl '\n'
const int N = 1500010;
const int K=500;
const ll mod=998244353;
const ll inf=1e18;

void solve(){
    int n,m;cin>>n>>m;
    if (n==1 && m==1) cout<<0<<endl;
    else cout<<(n+m-2)+min(n,m)<<endl;

}
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 86

**/