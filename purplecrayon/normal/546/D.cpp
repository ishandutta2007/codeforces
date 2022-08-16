#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const int MAXV = 5e6+10;
int pf[MAXV], ps[MAXV];

int cnt_pf(int n) {
    int ans = 0;
    int c=n;
    while (c > 1){
        int v = pf[c];
		while (c%v == 0) ans++, c /= v;
    }
    return ans;
}
void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
    for (int i = 1; i < MAXV; i++) ps[i] = cnt_pf(i)+ps[i-1];
}
vector<pair<int, int>> get_pf(int n){
    vector<pair<int, int>> r;
    int c=n;
    while (c > 1){
        int v = pf[c];
        r.emplace_back(v, 0);
		while (c%v == 0) r.back().second++, c /= v;
    }
    return r;
}
vector<pair<ll, int>> get_pf_big(ll n){
    vector<pair<ll, int>> r;
    for (ll i = 2; i*i <= n; i++) if (n%i == 0){
        r.emplace_back(i, 0);
        while (n%i == 0) r.back().second++, n /= i;
    }
    if (n>1) r.emplace_back(n, 1);
    return r;
}


void solve(){
    int a, b; cin >> a >> b;
    cout << ps[a]-ps[b] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T=1;
    cin >> T;
    while (T--) solve();
}