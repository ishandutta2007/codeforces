#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const int B = 300;

int n, q, jump[MAXN];
int a[MAXN], b[MAXN]; // b = a^-1

int dist(int x, int y) {
    int ans = 0;
    for (; x != y && ans <= B; ans++) 
        x = a[x];
    return ans;
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i], --a[i];
        b[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int c = i;
        for (int k = 0; k < B; k++) c = a[c];
        jump[i] = c;
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y, --x, --y;

            auto get_change = [&](int c) {
                vector<int> ans(B + 1);
                for (int i = 0; i <= B; i++) {
                    ans[i] = c;
                    c = b[c];
                }
                return ans;
            };

            swap(b[a[x]], b[a[y]]);
            swap(a[x], a[y]);

            auto add_change = [&](int c) {
                auto change = get_change(c);
                for (int k = 0; k <= B; k++) {
                    jump[change[B - k]] = c;
                    c = a[c];
                }
            };
            add_change(x);
            add_change(y);
        } else {
            int c, k; cin >> c >> k, --c;
            while (k >= B) c = jump[c], k -= B;
            while (k--) c = a[c];
            cout << c+1 << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}