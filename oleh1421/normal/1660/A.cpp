#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;
int a[N];
void solve(){
    ll a,b;cin>>a>>b;
    if (a>0) cout<<a+b*2+1<<endl;
    else cout<<1<<endl;


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