#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 1 << 18;

int q, d;
int cnt[2*N], sum[2*N], Lc[2*N], lazy[2*N];

void upd(int v, int x) {
    sum[v] += x * cnt[v];
    Lc[v] += x;
    lazy[v] += x;
}

void push(int v) {
    upd(v*2, lazy[v]);
    upd(v*2+1, lazy[v]);
    lazy[v] = 0;
}

void pull(int v) {
    cnt[v] = cnt[v*2] + cnt[v*2+1];
    sum[v] = sum[v*2] + sum[v*2+1];
    if (cnt[v*2]) Lc[v] = Lc[2*v];
    else Lc[v] = Lc[v*2+1];
}

int getcnt(int l, int r, int v = 1, int tl = 0, int tr = N) {
    if (tl >= r || tr <= l) return 0;
    if (tl >= l && tr <= r) return cnt[v];
    push(v);
    int mid = (tl + tr) / 2;
    return getcnt(l, r, v*2, tl, mid) + getcnt(l, r, v*2+1, mid, tr);
}

int gethard(int x, int& coc, int v = 1, int tl = 0, int tr = N) {
    if (cnt[v] == 0 || tl >= x) return 0;
    if (tr <= x && Lc[v] >= (cnt[v]-1) + coc) {
        int res = sum[v] - cnt[v] * coc - cnt[v] * (cnt[v]-1)/2;
        //cout << "gethard " << tl << " " << tr << " " << res << endl;
        coc += cnt[v];
        return res;
    }
    if (tl == tr - 1) { coc = inf; return 0; }
    push(v);
    int mid = (tl + tr) / 2;
    int res = gethard(x, coc, v*2+1, mid, tr);
    if (coc < inf) res += gethard(x, coc, v*2, tl, mid);
    return res;
}
void segset(int l, int r, int val, int v = 1, int tl = 0, int tr = N) {
    if (tl >= r || tr <= l) return;
    if (tl >= l && tr <= r) return upd(v, val);
    push(v);
    int mid = (tl + tr) / 2;
    segset(l, r, val, v*2, tl, mid);
    segset(l, r, val, v*2+1, mid, tr);
    pull(v);
}

void one_little_bitch(int x, int rig) {
    for (int v = 1, i = 17; i >= 0; v = 2*v + (x >> i & 1), --i) {
        push(v);
    }
    x += N;
    if (cnt[x]) cnt[x] = sum[x] = Lc[x] = 0;
    else
        cnt[x] = 1, sum[x] = Lc[x] = rig;

    while (x >>= 1) pull(x);
}

void run() {
    cin >> q >> d;

    set<int> pts;
    int res = 0;

    for (int i = 0; i < q; ++i) {
        int x; cin >> x;

        int c_r = getcnt(x+1, x+d+1);
        int c_l = getcnt(x-d, x);
        int tmp = pts.count(x);
        int c_mid = gethard(x, tmp);

        //cout << "Caesar " << c_l << " " << c_r << " " << c_mid << endl;

        int val = pts.count(x) ? -1 : 1;
        int change = c_l*(c_l-1)/2 + c_r*(c_r-1)/2 + c_mid;

        if (val == -1) pts.erase(x);
        else pts.emplace(x);

        segset(x-d, x, val);
        one_little_bitch(x, c_r);
        res += val * change;

        cout << res << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}