//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=1000000007ll;
const int A=1000100;
int pref[N];
int p[N];
void solve(){
    ll a,b,c,p;cin>>p>>a>>b>>c;
    a=((p+a-1)/a)*a;
    b=((p+b-1)/b)*b;
    c=((p+c-1)/c)*c;
    cout<<min({a,b,c})-p<<endl;


}
int32_t main()
{
//    srand(time(NULL));
//    freopen("subset.in","r",stdin);
//    freopen("subset.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*

4 3 5

*/