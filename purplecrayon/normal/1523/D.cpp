#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
void solve(){
    int n, m, _p; cin >> n >> m >> _p;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ll c=0;
        for (auto b : s) c *= 2, c += b-'0';
        a[i] = c;
    }
    ll ans = 0;
    auto get = [&](ll i) {
        if (__builtin_popcountll(i) > __builtin_popcountll(ans)) ans = i;
    };
    for (int rep = 0; rep < 50; rep++) {
        int i = rnd(0, n-1);

        int p = __builtin_popcountll(a[i]);
        vector<int> pos, rpos(m, -1), loc(p);
        for (int j = 0; j < m; j++) if ((a[i]>>j)&1) {
            rpos[j] = sz(pos);
            loc[rpos[j]] = j;
            pos.push_back(j);
        }
        vector<int> cnt(1<<p);
        for (int j = 0; j < n; j++) {
            ll cv = a[j]&a[i];

            int c = 0;
            for (int k = 0; k < m; k++) if ((cv>>k)&1) {
                c |= 1<<rpos[k];
            }
            //cerr << c << endl;

            cnt[c]++;
        }

        for(int j = p-1; j >= 0; --j) for(int mask = (1<<p)-1; mask >= 0; mask--)
            if(mask & (1<<j))
                cnt[mask^(1<<j)] += cnt[mask];

        //for (int i = 0; i < (1<<p); i++) cerr << cnt[i] << ' '; cerr << endl;

        for (int i = 0; i < (1<<p); i++) {
            if (cnt[i] >= (n+1)/2) {
                ll c = 0;
                for (int k = 0; k < p; k++) if ((i>>k)&1) c |= 1ll<<loc[k];
                get(c);
            }
        }
    }

    for (int i = m-1; i >= 0; i--) cout << ((ans>>i)&1);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}