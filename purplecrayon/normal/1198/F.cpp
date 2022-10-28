#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

// only take elements which cause the gcd to decrease
// this means that the size of the subset is < 9
// just random?

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
const double TIME_CUTOFF = 0.3;
double clock_begin;

double get_time() {
    return (clock() - clock_begin) / CLOCKS_PER_SEC;
}
bool try_done() {
    if (get_time() >= TIME_CUTOFF) {
        cout << "NO\n";
        exit(0);
        return 0;
    }
    return 1;
}


int n, a[MAXN], p[MAXN];
int ans[MAXN];

void solve() {
    cin >> n;
    int g = 0;
    for (int i = 0; i < n; i++) cin >> a[i], g = std::gcd(g, a[i]);
    if (g > 1) {
        cout << "NO\n";
        return;
    }
    iota(p, p+n, 0);

    while (try_done()) {
        shuffle(p, p+n, rng);
        int one = 0, two = 0;
        for (int i = 0; i < n; i++) {
            int c = p[i];
            int me = std::gcd(one, a[c]);
            if (me != one) {
                one = std::gcd(one, a[c]);
                ans[c] = 0;
            } else {
                two = std::gcd(two, a[c]);
                ans[c] = 1;
            }
        }
        if (one == 1 && two == 1) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << ans[i]+1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    clock_begin = clock();
    int T=1;
    // cin >> T;
    while (T--) solve();
}