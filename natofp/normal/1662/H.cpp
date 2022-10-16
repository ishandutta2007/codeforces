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

vector<ll> divs(ll x){
    vector<ll> ans;
    for(ll i=1;i*i<=x;i++){
        if(x % i == 0){
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    }
    return ans;
}

void solve(){
    ll w, l; cin >> w >> l;
    ll sum = w * 2 + (l - 2) * 2;
    auto pos = divs(sum);
    sort(pos.begin(), pos.end());
    vector<ll> ans;
    for(ll x : pos){
        if(x <= 2){
            ans.pb(x);
            continue;
        }
        // pionowo
        if(x > min(w, l)) continue;
        // l + (w - 2)
        // w + (l - 2)
        bool ok = false;
        if(l % x <= 1){
            if(l % x == 0){
                if((w - 2) % x == 0) ok = true;
            }
            if(l % x == 1){
                if((w - 1) % x == 0) ok = true;
            }
        }

        if(w % x <= 1){
            if(w % x == 0){
                if((l - 2) % x == 0) ok = true;
            }
            if(w % x == 1){
                if((l - 1) % x == 0) ok = true;
            }
        }
        if(ok) ans.pb(x);
    }
    cout << ans.size() << " ";
    for(ll x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}