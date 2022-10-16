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

ll ary(ll x){
    return x * (x + 1) / 2;
}

const int nax = 2e5 + 5;
ll n, k;
ll a[nax];
ll pref[nax];

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(k >= n){
        ll total = n * (k - 1);
        for(int i=1;i<=n;i++) total += a[i];
        total -= ary(n - 1);
        cout << total << "\n";
    }
    else{
        ll gain = ary(k - 1);
        pref[0] = 0;
        for(int i=1;i<=n;i++) pref[i] = pref[i - 1] + a[i];
        ll ans = 0;
        for(int i=k;i<=n;i++) ans = max(ans, pref[i] - pref[i - k]);
        ans += gain;
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}