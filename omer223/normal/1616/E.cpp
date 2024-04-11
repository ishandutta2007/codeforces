
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll INF = 1e15;
const int sz = 5e5;
string s, t;
int n;
int bit[sz];

int sum(int r) {
    if (r < 0)return 0;
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
        bit[idx] += delta;
}

void solve() { //CHECK FENWICK GOOD
    cin >> n >> s >> t;
    foru(i, 0, 3 * n)bit[i] = 0;
    foru(i, 0, n)add(i, 1);
    ll bst = INF, cur = 0;
    set<int> pos[26];
    foru(i, 0, n)pos[s[i] - 'a'].insert(i);
    foru(i, 0, n) {
        int ord = t[i] - 'a';
        ll bstbeat = INF, bstbeatpos = -1;
        foru(j, 0, ord) {
            auto x = pos[j].begin();
            if (x != pos[j].end()) {
                int crpos = sum(*x - 1);
                if (crpos < bstbeat) {
                    bstbeat = crpos;
                    bstbeatpos = *x;
                }
            }
        }
        if (bstbeatpos != -1)bst = min(bst, bstbeat + cur);
        auto x = pos[ord].begin();
        if (x == pos[ord].end())break;
        int crpos = sum(*x - 1);
        cur += crpos;
        add(*x, -1);
        pos[ord].erase(x);
    }
    if (bst >= INF/2)cout << -1 << '\n';
    else cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}