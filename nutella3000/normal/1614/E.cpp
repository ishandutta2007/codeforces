#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7;
const int N = 3e7, M = 2e9, mod = 1e9+1;

int n;
int sum[N], ch[N][2], Tsz = 1;

void make_childs(int v) {
    if (!ch[v][0])
        ch[v][0] = Tsz++, ch[v][1] = Tsz++;
}
int segget(int x, int pref = 0, int v = 0, int tl = 0, int tr = M) {
    if (tl == x && x == tr - 1) return tl+pref+sum[v];
    make_childs(v);
    int mid = (tl + tr) / 2;
    if (mid > x) return segget(x, pref, ch[v][0], tl, mid);
    return segget(x, pref+sum[ch[v][0]], ch[v][1], mid, tr);
}
void segset(int x, int val, int v = 0, int tl = 0, int tr = M) {
    if (tl > x || tr <= x) return;
    if (tl == x && tr - 1 == x) { sum[v] += val; return; }
    make_childs(v);
    int mid = (tl + tr) / 2;
    segset(x, val, ch[v][0], tl, mid);
    segset(x, val, ch[v][1], mid, tr);
    sum[v] = sum[ch[v][0]] + sum[ch[v][1]];
}
int revf(int y, int pref = 0, int v = 0, int tl = 0, int tr = M) {
    if (pref + sum[v] + tr-1 < y) return -1; 
    if (tl == tr - 1) return tl;
    make_childs(v);
    int mid = (tl + tr) / 2;
    int res = revf(y, pref, ch[v][0], tl, mid);
    if (res == -1) res = revf(y, pref+sum[ch[v][0]], ch[v][1], mid, tr);
    return res;
}


void run() {
    cin >> n;
    int last_ans = 0;
    for (int it = 0; it < n; ++it) {
        int T; cin >> T;
        int x1 = max(0ll, revf(T)), x2 = max(0ll, revf(T+1));
        segset(x1, -1), segset(x2, -1), segset(0, 1);

        int k; cin >> k;
        for (int i = 0; i < k; ++i) {
            int x; cin >> x; x = (x + last_ans) % mod;
            last_ans = segget(x);
            cout << last_ans << endl;
        }
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);

    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }

    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}