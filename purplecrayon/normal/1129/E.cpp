#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

int n, sub[MAXN], p[MAXN];

vector<int> range(vector<int> v, int l, int r) {
    vector<int> ans;
    for (int i = l; i <= r; i++) ans.push_back(v[i]);
    return ans;
}
vector<int> range(int l, int r) {
    vector<int> v;
    for (int i = l; i <= r; i++) v.push_back(i);
    return v;
}
int qry(vector<int> s, vector<int> t, int v) {
    cout << sz(s) << endl;
    for (auto c : s) cout << c+1 << ' '; cout << endl;
    cout << sz(t) << endl;
    for (auto c : t) cout << c+1 << ' '; cout << endl;
    cout << v+1 << endl;
    int ans; cin >> ans;
    return ans;
}

vector<pair<int, int>> ans;
void solve() {
    cin >> n;
    sub[0] = n;
    for (int i = 1; i < n; i++) {
        sub[i] = qry({0}, range(1, n-1), i);
    }
    iota(p, p+n, 0);
    sort(p, p+n, [&](int a, int b){ return sub[a] < sub[b]; });

    vector<int> cand{p[0]};
    for (int i = 1; i < n; i++) {
        int c = p[i];

        int cnt_child = qry({0}, cand, c);
        for (int rep = 0; rep < cnt_child; rep++) {
            assert(sz(cand));
            int lo = -1, hi = sz(cand)-1, mid = (lo+hi)/2;
            while (lo < mid && mid < hi) {
                if (qry({0}, range(cand, 0, mid), c)) hi = mid;
                else lo = mid;
                mid = (lo+hi)/2;
            }
            int child = cand[hi];
            ans.emplace_back(c, child);
            cand.erase(cand.begin() + hi);
        }
        cand.push_back(c);
    }
    assert(sz(cand) == 1 && cand[0] == 0);
    cout << "ANSWER\n";
    for (auto [a, b] : ans) {
        cout << a+1 << ' ' << b+1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}