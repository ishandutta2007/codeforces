#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, q;
map<ar<int, 3>, int> eq;
map<ar<int, 2>, int> rev;

map<ar<int, 2>, char> chr;

int get_eq(ar<int, 3> key) { assert(eq[key] <= 2); return eq[key]*(eq[key]-1)/2; }
int get_rev(ar<int, 2> key){ assert(rev[key] <= 2); return rev[key]*(rev[key]-1)/2; }
int cnt_eq = 0, cnt_rev = 0;

void solve(){
    cin >> n >> q;
    while (q--) {
        char c; cin >> c;
        if (c == '+') {
            int a, b; char x; cin >> a >> b >> x, --a, --b;
            chr[{a, b}] = x;
            if (a > b) swap(a, b);

            ar<int, 3> eq_key{a, b, int(x)};
            cnt_eq -= get_eq(eq_key);
            eq[eq_key]++;
            cnt_eq += get_eq(eq_key);

            ar<int, 2> rev_key{a, b};
            cnt_rev -= get_rev(rev_key);
            rev[rev_key]++;
            cnt_rev += get_rev(rev_key);
        } else if (c == '-') {
            int a, b; cin >> a >> b, --a, --b;
            char x = chr[{a, b}];
            if (a > b) swap(a, b);

            ar<int, 3> eq_key{a, b, int(x)};
            cnt_eq -= get_eq(eq_key);
            eq[eq_key]--;
            cnt_eq += get_eq(eq_key);

            ar<int, 2> rev_key{a, b};
            cnt_rev -= get_rev(rev_key);
            rev[rev_key]--;
            cnt_rev += get_rev(rev_key);
        } else if (c == '?') {
            int k; cin >> k;
            if (k&1) cout << (cnt_rev ? "YES\n" : "NO\n");
            else cout << (cnt_eq ? "YES\n" : "NO\n");
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}