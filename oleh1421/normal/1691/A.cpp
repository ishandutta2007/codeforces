//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=200100;

void solve(int Case){
    int n;cin>>n;
    int cnt[2];
    cnt[0]=cnt[1]=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[abs(x)%2]++;
    }
    cout<<min(cnt[0],cnt[1])<<endl;




}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}