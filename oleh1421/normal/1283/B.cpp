#pragma GCC Optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
const long long mod=998244353;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
void solve(){
    int n,k;cin>>n>>k;
    int a=(n/k);
    n%=k;
    cout<<min(n,k/2)+a*k<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();

    }

    return 0;
}