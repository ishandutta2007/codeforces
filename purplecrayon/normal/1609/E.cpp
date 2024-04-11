#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

struct node {
    int mask[3]={}; // largest subsequence without this character
    int ab = 0, bc = 0, abc = 0; // largest without this sequence
};
node make_data(char c) {
    int x = c - 'a';
    node ans; ans.ab = ans.bc = ans.abc = 1;
    for (int i = 0; i < 3; i++) if (i != x) {
        ans.mask[i] = 1;
    }
    return ans;
}
node comb(node a, node b) {
    node ans; 
    for (int i = 0; i < 3; i++) {
        ans.mask[i] = a.mask[i] + b.mask[i];
    }

    ans.ab = max(a.ab, b.ab);
    ans.ab = max(ans.ab, a.ab + b.mask[1]);
    ans.ab = max(ans.ab, a.mask[0] + b.ab);

    ans.bc = max(a.bc, b.bc);
    ans.bc = max(ans.bc, a.bc + b.mask[2]);
    ans.bc = max(ans.bc, a.mask[1] + b.bc);

    ans.abc = max({a.abc, b.abc, ans.ab, ans.bc});
    ans.abc = max(ans.abc, a.mask[0] + b.abc);
    ans.abc = max(ans.abc, a.abc + b.mask[2]);
    ans.abc = max(ans.abc, a.ab + b.bc);
    return ans;
}

int n, q;
string s;
node t[4*MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = make_data(s[tl]);
    else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm), build(2*v+1, tm+1, tr);
        t[v] = comb(t[2*v], t[2*v+1]);
    }
}
void upd(int v, int tl, int tr, int pos, char x) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        t[v] = make_data(x);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2*v, tl, tm, pos, x), upd(2*v+1, tm+1, tr, pos, x);
    t[v] = comb(t[2*v], t[2*v+1]);
}
void solve() {
    cin >> n >> q >> s;
    build(1, 0, n-1);
    while (q--) {
        int pos; char c; cin >> pos >> c, --pos;
        upd(1, 0, n-1, pos, c);
        s[pos] = c;
        cout << n - t[1].abc << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}