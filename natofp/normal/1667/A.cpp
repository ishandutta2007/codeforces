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

const int nax = 5005;
ll a[nax];
int n;

ll prefix(int len){
    ll c = 0;
    ll last = 0;
    for(int i=len;i>=1;i--){
        ll teraz = (last + 1 + a[i] - 1) / a[i];
        c += teraz;
        last = teraz * a[i];
    }
    return c;
}

ll sufix(int from){
    ll c = 0;
    ll last = 0;
    for(int i=from;i<=n;i++){
        ll teraz = (last + 1 + a[i] - 1) / a[i];
        c += teraz;
        last = teraz * a[i];
    }
    return c;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 1e18;
    for(int pref=1;pref<=n;pref++){
        ans = min(ans, prefix(pref - 1) + sufix(pref + 1));
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}