#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int inv = (mod+1)/2;
ll solve(ll x){
    ll len = 1, st1 = 1, st2 = 2, st = 0;
    ll ans = 0;
    while(x){
        if(x<=len) len = x;
        if(st==0){
            ll ed = st1 + ((len-1) % mod) * 2 % mod;
            ed %= mod;
            ans += (st1 + ed) % mod * (len%mod) % mod * inv % mod;
//            cout<<(st1 + ed) % mod * len % mod * inv % mod<<endl;
            st1 = ed + 2;
        }
        else{
            ll ed = st2 + ((len-1) % mod) * 2 % mod;
            ed %= mod;
            ans += (st2 + ed) % mod * (len%mod) % mod * inv % mod;
//            cout<<(st2 + ed) % mod * len % mod * inv % mod<<endl;
            st2 = ed + 2;
        }
        ans %= mod, st1 %= mod, st2 %= mod;
        x -= len;
        st ^= 1;
        len <<= 1;
    }
    return ans % mod;
}
int main(){
    ll l,r;
    while(cin>>l>>r){
        cout<<(solve(r)-solve(l-1)+mod)%mod<<endl;
    }
}