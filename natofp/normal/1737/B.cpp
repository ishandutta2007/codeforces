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
#define mt make_tuple

using namespace std;

int gut[50];

ll my_sqrt(ll x){
    ll low = 1;
    ll high = 1e9 + 1e8;
    while(low < high){
        ll mid = (low + high + 1) / 2;
        if(mid * mid <= x) low = mid;
        else high = mid - 1;
    }
    return low;
}

bool good(ll x){
    return (x % my_sqrt(x) == 0);
}

ll ask(ll r){
    if(r <= 49){
        ll sum = 0;
        for(int i=1;i<=r;i++) sum += gut[i];
        return sum;
    }
    // 49 = 19
    ll xd = my_sqrt(r);
    ll dif = xd - 7;
    ll ans = dif * 3 + 19;
    ll haha = xd * xd;
    if(haha + xd <= r) ans++;
    if(haha + xd + xd <= r) ans++;
    return ans;
}

void solve(){
    ll l, r; cin >> l >> r;
    cout << ask(r) - ask(l - 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=49;i++){
        if(good(i)){
            gut[i] = 1;
        }
    }
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}