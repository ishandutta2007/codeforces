#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 998244353;
const int INF = 1e9+10;

struct S {
    int time;
    set<ar<int, 2>> s;
    vector<ar<int, 4>> ev; //l, r, time, type (+1, -1)

    S(): s(), time(), ev() {}

    bool contain_any(int l, int r) {
        auto small_it = s.lower_bound({l, -1});
        if (small_it == s.end()) return 0;
        auto small = *small_it;
        return l <= small[0] && small[1] <= r;
    }
    set<ar<int, 2>>::iterator contained(int l, int r) {
        auto big_it = s.upper_bound({l, INF});
        if (big_it == s.begin()) return s.end();
        big_it = prev(big_it);
        auto big = *big_it;
        return (big[0] <= l && r <= big[1] ? big_it : s.end());
    }
    void push(int l, int r) {
        if (!contain_any(l, r)) {
            auto big = contained(l, r);
            if (big != s.end()) {
                ev.push_back({(*big)[0], (*big)[1], time, -1});
                s.erase(big);
            }
            s.insert({l, r});
            ev.push_back({l, r, time, +1});
        }
        time++;
    }
    void pop() {
        time--;
        while (sz(ev) && ev.back()[2] == time) {
            ar<int, 2> c{ev.back()[0], ev.back()[1]};
            if (ev.back()[3] == +1) s.erase(c);
            else s.insert(c);

            ev.pop_back();
        }
    }
    size_t size() {
        return s.size();
    }
};

int n, st[MAXN], en[MAXN], tt=0;
vector<int> one[MAXN], two[MAXN];
S s;

void dfs1(int c=0, int p=-1) {
    st[c] = tt++;
    for (auto nxt : two[c]) if (nxt != p) dfs1(nxt, c);
    en[c] = tt-1;
}
int dfs2(int c=0, int p=-1) {
    s.push(st[c], en[c]);
    int ans = sz(s);
    for (auto nxt : one[c]) if (nxt != p) {
        ans = max(ans, dfs2(nxt, c));
    }
    s.pop();
    return ans;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) one[i].clear(), two[i].clear();
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        one[p].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        two[p].push_back(i);
    }
    dfs1();
    s = S();
    cout << dfs2() << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}