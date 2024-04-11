#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = 3e5 + 1;

int n;
int a[max_n], b[max_n];
deque<int> id[max_n];
int last[4 * max_n];

void scan() {
    cin >> n;

    for(int i = 0;i <= n;i++)
        id[i].clear();

    for(int i = 0;i <= 4 * n;i++) last[i] = 0;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        id[a[i]].emplace_back(i);
    }

    for(int i = 0;i < n;i++)
        cin >> b[i];
}


void upd(int v, int l, int r, int id, int x) {
    if (l > id || r < id) return;
    if (l == id && r == id) {
        last[v] = x;
        return;
    }
    int m = ((l + r) / 2);
    upd(v * 2, l, m, id, x);
    upd(v * 2 + 1, m + 1, r, id, x);
    last[v] = max(last[v * 2], last[v * 2 + 1]);
}

int get(int v, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return last[v];
    int m = (l + r) / 2;
    return max(get(v * 2, l, m, ql, qr), get(v * 2 + 1, m + 1, r, ql, qr));
}

bool solve() {
    scan();

    for(int temp1 = 0;temp1 < n;temp1++) {
        int v = b[temp1];
        if (id[v].empty()) return false;
        if (get(1, 1, n, v, n) > id[v].front()) return false;
        upd(1, 1, n, v, id[v].front());
        id[v].pop_front();
    }
    return true;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}