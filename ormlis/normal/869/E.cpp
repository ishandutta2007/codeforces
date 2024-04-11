#include <bits/stdc++.h>
 
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
 
typedef unsigned long long ll;
 
using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2501;
const int P = 998244353;
const int md = 1e9 + 7;
 
double getTime() { return clock() / (double) CLOCKS_PER_SEC; };
 
int fenw[maxN][maxN];
int cP[100001];
int n, m;
 
void upd(int i, int j, int x) {
    for(; i < n; i = i | (i + 1)) {
        for(int e = j; e < m; e = e | (e + 1)) {
            fenw[i][e] ^= x;
        }
    }
}
 
int get(int i, int j) {
    int res = 0;
    for(; ~i; i = ((i + 1) & i) - 1) {
        for(int e = j; ~e; e = ((e + 1) & e) - 1) {
            res ^= fenw[i][e];
        }
    }
    return res;
}
 
void solve() {
    cP[0] = 1;
    for(int i = 1; i <= 100000; ++i) cP[i] = (1ll * cP[i-1] * P) % md;
    map<pair<int, int>, int> mp;
    int cnt = 0;
    int q; cin >> n >> m >> q;
    range(_, q) {
        int t, r1, c1, r2, c2; cin >> t >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        if (t == 1) {
            cnt++;
            if (r1 > r2) swap(r1, r2);
            if (c1 > c2) swap(c1, c2);
            pair<int, int> kek = {r1, c1};
            int cur = cP[cnt];
            mp[kek] = cur;
            upd(r1, c1, cur);
            upd(r1, c2 + 1, cur);
            upd(r2 + 1, c1, cur);
            upd(r2 + 1, c2 + 1, cur);
        } else if (t == 2) {
            if (r1 > r2) swap(r1, r2);
            if (c1 > c2) swap(c1, c2);
            pair<int, int> kek = {r1, c1};
            int cur = mp[kek];
            upd(r1, c1, cur);
            upd(r1, c2 + 1, cur);
            upd(r2 + 1, c1, cur);
            upd(r2 + 1, c2 + 1, cur);
            mp.erase(kek);
        } else {
            //cout << get(r1, c1) << " " <<  get(r2, c2) << "\n";
            if (get(r1, c1) != get(r2, c2)) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}