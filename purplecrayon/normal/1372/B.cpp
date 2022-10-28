#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1e9+10, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    ll n; cin >> n;
    ll k = 1;
    for (ll i = 2; i*i <= n; i++){
        if (n%i == 0) k = max(k, max(i, n/i));
    }
    cout << k << " " << n-k << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}