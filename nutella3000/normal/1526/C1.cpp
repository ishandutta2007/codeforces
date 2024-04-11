#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back

const int inf = 2e9 + 2;
const int max_n = (1 << 17);

int n;
int mn[2 * max_n], lazy[2 * max_n];

void upd(int v, int x) {
    mn[v] += x;
    lazy[v] += x;
}

void push(int v) {
    upd(v * 2, lazy[v]);
    upd(v * 2 + 1, lazy[v]);
    lazy[v] = 0;
}

void segset(int l, int x, int v = 1, int tl = 0, int tr = max_n) {
    if (tr <= l) return;
    if (tl >= l) {
        upd(v, x);
        return;
    }
    push(v);
    int mid = (tl + tr) / 2;
    segset(l, x, v * 2, tl, mid);
    segset(l, x, v * 2 + 1, mid, tr);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]); 
}



void run() {
    cin >> n;
    vector<int> a(n), id(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    iota(all(id), 0);
    sort(all(id), [&](int v1, int v2) { return a[v1] > a[v2]; });

    int res = 0;
    for (int i : id) {
        segset(i, a[i]);
        if (mn[1] < 0) {
            segset(i, -a[i]);
        }else ++res;
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    
    int t = 1;
    //cin >> t;
    while(t--) run();
}