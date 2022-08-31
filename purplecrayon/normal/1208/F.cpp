#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

ar<int, 2> merge(ar<int, 2> a, ar<int, 2> b) {
    ar<int, 2> c{-1, -1};
    for (auto v : a) c[0] = max(c[0], v);
    for (auto v : b) c[0] = max(c[0], v);

    for (auto v : a) if (v != c[0]) c[1] = max(c[1], v);
    for (auto v : b) if (v != c[0]) c[1] = max(c[1], v);

    return c;
}
void merge_self(ar<int, 2>& a, ar<int, 2> b) {
    a = merge(a, b);
}

const int MAXV = 2e6+10, MAXB = 21;

int n, a[MAXN];
ar<int, 2> super[1<<MAXB];

void solve(){
    cin >> n;

    fill(super, super+(1<<MAXB), ar<int, 2>{-1, -1});
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        merge_self(super[a[i]], {i, -1});
    }

    for (int i = 0; i < MAXB; i++) for (int mask = (1<<MAXB)-1; mask >= 0; mask--) {
        if ((mask>>i)&1) merge_self(super[mask^(1<<i)], super[mask]);
    }

    auto on = [&](int i, int mask) {
        return super[mask][0] > i && super[mask][1] > i;
    };

    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        int me = 0, mask = 0;
        for (int j = MAXB-1; j >= 0; j--) {
            if ((a[i]>>j)&1) {
                me |= 1<<j;
                continue;
            }
            if (on(i, mask|(1<<j))) {
                me |= 1<<j;
                mask |= 1<<j;
            }
        }
        if (me == 15) {
            cerr << i << endl;
        }
        ans = max(ans, me);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}