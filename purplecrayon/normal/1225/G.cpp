#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
double clock_begin = 0;
double get_time(){ return (clock()-clock_begin)/CLOCKS_PER_SEC; }

void solve(){
    clock_begin = clock();

    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& c : a) cin >> c;

    auto f = [&](int x, int y){
        int v = x+y;
        while (v%k == 0) v /= k;
        return v;
    };

    while (get_time() < 1.95) {
        auto b = a;

        vector<ar<int, 2>> ans;
        for (int rep = 0; rep < n-1; rep++) {
            int x_i = rnd(0, sz(b)-1);
            swap(b[x_i], b[sz(b)-1]);
            int y_i = rnd(0, sz(b)-2);
            swap(b[y_i], b[sz(b)-2]);

            int x = b[sz(b)-1], y = b[sz(b)-2];
            ans.push_back({x, y});
            b.pop_back(), b.pop_back();
            b.push_back(f(x, y));
        }

        assert(sz(b) == 1);
        if (b[0] != 1) continue;

        cout << "YES\n";
        for (auto c : ans) cout << c[0] << ' ' << c[1] << '\n';
        return;
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}