#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 1e5;

char lg[MAXN + 1];

int a[MAXN + 1], b[MAXN + 1];

vector <int> g[MAXN + 1];
int lvl[MAXN + 1];

int idl[MAXN + 1], idr[MAXN + 1];
int cnt;

void dfs(int nod) {
    idl[nod] = ++cnt;
    for(auto it : g[nod]) {
        if(lvl[it] == 0) {
            lvl[it] = lvl[nod] + 1;
            dfs(it);
        }
    }
    idr[nod] = cnt;
}

struct Line {
    ll a, b;
    bool operator <(const Line &other) const {
        if(a == other.a)
            return b < other.b;
        return a > other.a;
    }
}lines[MAXN + 1];

vector <int> aint[4 * MAXN + 1];

inline void refresh(int nod) {
    int sz1 = aint[2 * nod].size(), sz2 = aint[2 * nod + 1].size();
    int i = 0, j = 0;
    while(i < sz1 && j < sz2) {
        if(lines[aint[2 * nod][i]] < lines[aint[2 * nod + 1][j]]) {
            aint[nod].push_back(aint[2 * nod][i]);
            i++;
        }
        else {
            aint[nod].push_back(aint[2 * nod + 1][j]);
            j++;
        }
    }
    while(i < sz1) {
        aint[nod].push_back(aint[2 * nod][i]);
        i++;
    }
    while(j < sz2) {
        aint[nod].push_back(aint[2 * nod + 1][j]);
        j++;
    }
}

inline ll get(Line l, int x) {
    return 1LL * l.a * x + l.b;
}

inline long double inter(Line l1, Line l2) {
    if(l1.a == l2.a)
        return 1.0 * INF;
    return 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
}

int stk[MAXN + 1];

inline void Batch(int nod) {
    refresh(nod);
    int sz = 0;
    for(auto it : aint[nod]) {
        while(sz >= 2 && inter(lines[stk[sz - 1]], lines[stk[sz]]) - inter(lines[stk[sz - 1]], lines[it]) >= 0) {
            sz--;
        }
        stk[++sz] = it;
    }
    aint[nod].resize(sz);
    for(int i = 1; i <= sz; i++) {
        aint[nod][i - 1] = stk[i];
    }
}

int fr[4 * MAXN + 1];

void update(int nod, int left, int right, int pos) {
    fr[nod]++;
    if(left == right) {
        aint[nod].push_back(left);
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * nod, left, mid, pos);
        else
            update(2 * nod + 1, mid + 1, right, pos);
        if(fr[nod] == right - left + 1)
            Batch(nod);
    }
}

int n;

inline void addLine(ll a, ll b, int pos) {
    lines[pos] = {a, b};
    update(1, 1, n, pos);
}

ll query(int nod, int left, int right, int l, int r, int x) {
    if(l <= left && right <= r) {
        int sz = aint[nod].size();
        int res = -1;
        for(int step = 1 << lg[sz]; step; step >>= 1) {
            if(res + step + 1 < sz && inter(lines[aint[nod][res + step]], lines[aint[nod][res + step + 1]]) - 1.0 * x <= 0)
                res += step;
        }
        res++;
        return get(lines[aint[nod][res]], x);
    }
    else {
        int mid = (left + right) / 2;
        ll ans = INF;
        if(l <= mid)
            ans = min(ans, query(2 * nod, left, mid, l, r, x));
        if(mid < r)
            ans = min(ans, query(2 * nod + 1, mid + 1, right, l, r, x));
        return ans;
    }
}

ll dp[MAXN + 1];

void solve(int nod) {
    for(auto it : g[nod]) {
        if(lvl[nod] < lvl[it])
            solve(it);
    }
    if(idl[nod] < idr[nod])
        dp[nod] = query(1, 1, n, idl[nod] + 1, idr[nod], a[nod]);
    addLine(b[nod], dp[nod], idl[nod]);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lvl[1] = 1;
    dfs(1);
    for(i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    solve(1);
    for(i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}