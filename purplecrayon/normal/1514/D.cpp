#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

int n, q, a[MAXN];
vector<int> loc[MAXN];

int cnt(int x, int l, int r) {
    return upper_bound(loc[x].begin(), loc[x].end(), r)-lower_bound(loc[x].begin(), loc[x].end(), l);
}

void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i], --a[i];
        loc[a[i]].push_back(i);
    }
    while (q--) {
        int l, r; cin >> l >> r, --l, --r;
        
        int len = r-l+1;

        int ans = 1;

        const int MAGIC = 50;
        for (int rep = 0; rep < MAGIC; rep++) {
            int x = a[rnd(l, r)], me = cnt(x, l, r);
            if (me <= (len+1)/2) continue;

            ans = 2*me-len;
            break;
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}