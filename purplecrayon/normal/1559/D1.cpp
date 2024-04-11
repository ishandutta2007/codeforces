#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

int n, m1, m2;
int ans = 0;
vector<ar<int, 2>> pr;

vector<int> set2[MAXN];
set<pair<int, int>> vals1[MAXN];
int par1[MAXN], par2[MAXN];

set<int> roots, use;

int find_set1(int v){ return v==par1[v] ? v : par1[v] = find_set1(par1[v]); }
int find_set2(int v){ return v==par2[v] ? v : par2[v] = find_set2(par2[v]); }


bool valid(int v) {
    if (v != par1[v]) return 0;
    int mn = vals1[v].begin()->first, mx = vals1[v].rbegin()->first;
    return mn != mx;
}
int merge1(int a, int b) {
    a = find_set1(a), b = find_set1(b);
    if (a == b) return -1;
    if (sz(vals1[a]) < sz(vals1[b])) swap(a, b);
    for (auto c : vals1[b]) {
        vals1[a].insert(c);
    }
    vals1[b].clear();
    par1[b] = a;

    roots.erase(b);
    use.erase(b), use.erase(a);

    if (valid(a)) {
        use.insert(a);
    }
    if (valid(b)) {
        use.insert(b);
    }
    return a;
}
int merge2(int a, int b) {
    a = find_set2(a), b = find_set2(b);
    if (a == b) return -1;
    if (sz(set2[a]) < sz(set2[b])) swap(a, b);

    for (auto c : set2[b]) {
        int c_root = find_set1(c);

        use.erase(c_root);
        vals1[c_root].erase({b, c});
        vals1[c_root].insert({a, c});
        if (valid(c_root)) {
            use.insert(c_root);
        }

        set2[a].push_back(c);
    }
    set2[b].clear();
    par2[b] = a;

    return a;
}
void solve(){
    cin >> n >> m1 >> m2;
    //for everything that changes -> update the min/max in d1

    iota(par1, par1+n, 0), iota(par2, par2+n, 0);

    for (int i = 0; i < n; i++) {
        vals1[i].insert({i, i});
        set2[i].push_back(i);
        roots.insert(i);
    }

    while (m1--) {
        int a, b; cin >> a >> b, --a, --b;
        merge1(a, b);
    }
    while (m2--) {
        int a, b; cin >> a >> b, --a, --b;
        merge2(a, b);
    }

    /*
    for (int i = 0; i < n; i++) cerr << find_set1(i) << ' '; cerr << endl;
    for (int i = 0; i < n; i++) cerr << find_set2(i) << ' '; cerr << endl;
    for (int i = 0; i < n; i++) if (par1[i] == i) {
        cerr << "ROOT: " << i << endl;
        for (auto c : vals1[i]) {
            cerr << c.first << ' ' << c.second << '\n';
        }
        cerr << endl;
    }


    cerr << "all roots: "; for (auto c : roots) cerr << c << ' '; cerr << endl;
    cerr << "use: "; for (auto c : use) cerr << c << ' '; cerr << endl;
    */

    while (sz(roots) > 1 && sz(use)) {
        int a = *use.begin();
        int b = *roots.begin();
        if (a == b) b = *next(roots.begin());

        auto he = *vals1[b].begin();

        assert(a != b);
        assert(valid(a));
        auto me = *vals1[a].begin();
        if (me.first == he.first) me = *vals1[a].rbegin();

        assert(me.first != he.first);

        ans++;
        pr.push_back({he.second, me.second});

        merge2(he.second, me.second), merge1(he.second, me.second);
    }
    //cerr << "done\n";

    if (sz(roots) > 1) {
        vector<int> left(n, -1);
        for (int i = 0; i < n; i++) if (par1[i] == i) {
            assert(!valid(i));

            //cerr << i << endl;
            int only = vals1[i].begin()->first;
            left[only] = i;
        }

        int last = -1;
        for (int i = 0; i < n; i++) if (left[i] != -1) {
            int c = left[i];
            if (last != -1) {
                auto he = *vals1[last].begin();
                auto me = *vals1[c].begin();

                assert(he.first != me.first);
                merge2(he.second, me.second), merge1(he.second, me.second);

                ans++;
                pr.push_back({he.second, me.second});
            }
            last = find_set1(c);
        }

    }

    cout << ans << '\n';
    for (auto c : pr) cout << c[0]+1 << ' ' << c[1]+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}