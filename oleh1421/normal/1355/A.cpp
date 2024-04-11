#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=2010;
ll f(ll x){
    ll mn=10ll;
    ll mx=0ll;
    while (x){
        mn=min(mn,x%10ll);
        mx=max(mx,x%10ll);
        x/=10ll;
    }
    return mn*mx;
}
void solve(){
    ll x,k;cin>>x>>k;
    k--;
    while (f(x)>0 && k>0){
        x+=f(x);
        k--;
    }
    cout<<x<<endl;

}
int main()
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