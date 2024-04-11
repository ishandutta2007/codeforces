#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
const ll mod=1000000007;
int a[N];
ll dv(ll a,ll b){
    if (a<0) return 0;
    return a/b+1;
}
void solve(){
    int l,r;cin>>l>>r;
    int pw=1;
    ll res=r-l;
    for (int i=1;i<=9;i++){
        pw*=10;
        res+=dv(r-pw,pw)-dv(l-pw,pw);
    }
    cout<<res<<endl;

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}