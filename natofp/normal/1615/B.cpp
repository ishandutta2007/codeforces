#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

ll ok(ll r, int b){
    r -= (1 << b) - 1;
    if(r <= 0) return 0;
    ll ful = (1 << b) * 2;
    ll c = r / ful;
    ll ans = c * ful / 2;
    r -= c * ful;
    ans += min(r, (1LL<<b));
    return ans;
}

void solve(){
    ll l, r; cin >> l >> r;
    ll ans = 0;

    for(int i=0;i<=20;i++){
        ll c = ok(r, i) - ok(l - 1, i);
        ans = max(ans, c);
    }

    cout << r - l + 1 - ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}