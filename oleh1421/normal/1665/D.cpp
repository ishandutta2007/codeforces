#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
//#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=200010;
const int L=20;
const ll mod=998244353;
ll ask(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<endl;
    ll ans;cin>>ans;
    return ans;
}
void solve(){
    ll a=0ll;
    for (int i=0;i<30;i++){
        ll g=ask(a+(1ll<<i),a+(1ll<<(i+1ll))+(1ll<<i));
        if ((g%(1ll<<(i+1)))==0ll) {
            a-=(1ll<<i);
        }
    }
    cout<<"! "<<-a<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
608
7 11 12 13 14 15 17 19


4
5 100
1 10
10 1
100 100
**/