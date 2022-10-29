#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main(){
    ll N;
    ld p;
    cin >> N >> p;
    const ll P = llround(p * 1e4);
    ll ok = N, ng = -1;
    auto binom = [](ll n, ll r){
        if(n < r || r < 0) return 0LL;
        ll ans = 1;
        for(ll i = 0; i < r; i++){
            ans *= n - i;
            ans /= i + 1;
        }
        return ans;
    };
    auto check = [&](ll K) -> bool {
        return (binom(K, 3) * 2 + binom(K, 2) * binom(N - K, 1) * 2 + binom(K, 1) * binom(N - K, 2)) * 10000 >= P * binom(N, 3) * 2;
    };
    while(abs(ok - ng) > 1){
        ll cen = (ok + ng) / 2;
        (check(cen) ? ok : ng) = cen;
    }
    cout << ok << endl;
}