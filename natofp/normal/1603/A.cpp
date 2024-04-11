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


void solve(){
    int n; cin >> n;
    bool ok = true;
    vector<int> a;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a.pb(x);
    }
    ll cur = 2;
    for(int i=0;i<n;i++){
        if(a[i] % cur == 0) ok = false;
        if(cur < 2e9){
            ll nxt = (i + 3);
            ll g = __gcd(cur, nxt);
            cur = cur * nxt / g;
        }
    }
    if(ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}