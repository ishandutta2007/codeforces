#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

struct basis {
    static constexpr int D = 15;

    ll base[D]={};
    ll who[D]={};
    void add(ll x, ll me) {
        for (int i = 0; i < D; i++) if ((x>>i)&1) {
            if (!base[i]) {
                base[i] = x;
                who[i] = me;
                return;
            }
            x ^= base[i];
            me ^= who[i];
        }
    }
    ll contains(ll x) {
        ll me = 0;
        for (int i = 0; i < D; i++) if ((x>>i)&1) {
            if (!base[i]) return -1;
            x ^= base[i];
            me ^= who[i];
        }
        return me;
    }

};


const int LEFT = basis::D;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;

    vector<ar<int, 3>> ans;
    auto op = [&](int i, int j, int k) {
        a[i] ^= 1, a[j] ^= 1, a[k] ^= 1;
        ans.push_back({i, j, k});
    };

    while (sz(a) > LEFT) {
        int l = sz(a)-6, r = sz(a)-1;

        vector<ar<ll, 3>> cur;
        auto add = [&](int i, int dist) {
            int prv = i-dist, nxt = i+dist;
            if (nxt > r || nxt < l) return 0;

            ll cur_mask = 0;
            if (i >= l) cur_mask ^= 1ll<<(i-l);
            if (prv >= l) cur_mask ^= 1ll<<(prv-l);
            cur_mask ^= 1ll<<(nxt-l);

            cur.push_back({cur_mask, i, dist});
            return 1;
        };

        for (int i = l; i <= r; i++) {
            int mid = l-1;
            add(mid, i-mid);
            for (int dist = 1; ; dist++) {
                if (!add(i, dist)) break;
            }
        }
        

        vector<int> choose;

        ll my_mask = 0;
        for (int i = l; i <= r; i++) if (a[i]) my_mask ^= 1ll<<(i-l);

        for (int i = 0; i < sz(cur); i++) for (int j = i+1; j < sz(cur); j++) {
            if ((cur[i][0]^cur[j][0]) == my_mask)
                choose = {i, j};
        }
        for (int i = 0; i < sz(cur); i++) if (cur[i][0] == my_mask) choose = {i};

        for (int i : choose) {
            int mid = cur[i][1], dist = cur[i][2];
            op(mid-dist, mid, mid+dist);
        }
        for (int rep = 0; rep < 6; rep++) {
            assert(a.back() == 0);
            a.pop_back();
        }
    }

    int l = 0, r = sz(a)-1;

    basis b;
    vector<ar<int, 2>> cur;
    for (int i = l; i <= r; i++) for (int dist = 1; ; dist++) {
        int prv = i-dist, nxt = i+dist;
        if (nxt > r || prv < l) break;

        ll cur_mask = 1ll<<(i-l);
        if (prv >= l) cur_mask ^= 1ll<<(prv-l);
        if (prv <= r) cur_mask ^= 1ll<<(nxt-l);
        b.add(cur_mask, 1ll<<sz(cur));

        cur.push_back({i, dist});
    }
    
    ll my_mask = 0;
    for (int i = l; i <= r; i++) if (a[i]) my_mask ^= 1ll<<(i-l);

    ll chose = b.contains(my_mask);
    if (chose == -1){ cout << "NO\n"; return; }

    cout << "YES\n";
    for (int i = 0; i < sz(cur); i++) if ((chose>>i)&1) {
        int mid = cur[i][0], dist = cur[i][1];
        op(mid-dist, mid, mid+dist);
    }
    cout << sz(ans) << '\n';
    for (auto c : ans) cout << c[0]+1 << ' ' << c[1]+1 << ' ' << c[2]+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}