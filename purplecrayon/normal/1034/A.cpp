#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

const int MAXV = 1.5e7+10;
int pf[MAXV];

void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}

int n, a[MAXN];
int has[MAXV];

void solve(){
    cin >> n;
    pre();

    int g = 0;
    for (int i = 0; i < n; i++) cin >> a[i], g = std::gcd(g, a[i]), has[a[i]]++;

    int ans = n;
    const int BOUND = MAXV/g+1;
    for (int i = 2; i < MAXV; i++) if (pf[i] == i && i < BOUND) {
        int cnt = 0, c = g*i;
        for (int j = c; j < MAXV; j += c) cnt += has[j];
        ans = min(ans, n-cnt);
    }
    cout << (ans == n ? -1 : ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}