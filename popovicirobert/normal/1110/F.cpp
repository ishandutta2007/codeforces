#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 5e5;

class SegTree {

private:

    const ll INF = 1e18;

    vector < pair <ll, ll> > aint;
    int n;

    inline void solve_lazy(int nod) {
        if(aint[nod].second == 0) {
            return ;
        }
        if(2 * nod + 1 <= 4 * n) {
            aint[2 * nod].second += aint[nod].second;
            aint[2 * nod + 1].second += aint[nod].second;
        }
        aint[nod].first += aint[nod].second;
        aint[nod].second = 0;
    }
    inline void refresh(int nod) {
        solve_lazy(2 * nod), solve_lazy(2 * nod + 1);
        aint[nod].first = min(aint[2 * nod].first, aint[2 * nod + 1].first);
    }

public:

    inline void init(int _n) {
        n = _n;
        aint.resize(4 * n + 1);
    }

    void fix(int nod, int left, int right, int pos, ll val) {
        if(left == right) {
            aint[nod].first = val;
        }
        else {
            int mid = (left + right) / 2;
            if(pos <= mid) fix(2 * nod, left, mid, pos, val);
            else fix(2 * nod + 1, mid + 1, right, pos, val);
            refresh(nod);
        }
    }
    void update(int nod, int left, int right, int l, int r, ll val) {
        solve_lazy(nod);
        if(l <= left && right <= r) {
            aint[nod].second += val;
            solve_lazy(nod);
        }
        else {
            int mid = (left + right) / 2;
            if(l <= mid) update(2 * nod, left, mid, l, r, val);
            if(mid < r) update(2 * nod + 1, mid + 1, right, l, r, val);
            refresh(nod);
        }
    }
    ll query(int nod, int left, int right, int l, int r) {
        solve_lazy(nod);
        if(l <= left && right <= r) {
            return aint[nod].first;
        }
        else {
            int mid = (left + right) / 2;
            ll ans = INF;
            if(l <= mid) ans = min(ans, query(2 * nod, left, mid, l, r));
            if(mid < r) ans = min(ans, query(2 * nod + 1, mid + 1, right, l, r));
            refresh(nod);
            return ans;
        }
    }
};

vector < pair <int, int> > g[MAXN + 1];
int idl[MAXN + 1], idr[MAXN + 1], n;

bool leaf[MAXN + 1];
vector <int> leaves;

void dfs(int nod, int &sz, SegTree &st, ll dst) {
    idl[nod] = ++sz;
    if(leaf[nod]) {
        st.fix(1, 1, 2 * n, sz, dst);
    }
    else {
        st.fix(1, 1, 2 * n, sz, INF);
    }
    for(auto it : g[nod]) {
        dfs(it.first, sz, st, dst + it.second);
    }
    idr[nod] = ++sz;
    if(leaf[nod]) {
        st.fix(1, 1, 2 * n, sz, dst);
    }
    else {
        st.fix(1, 1, 2 * n, sz, INF);
    }
}

struct Query {
    int l, r, pos;
};

vector <Query> qry[MAXN + 1];
ll sol[MAXN + 1];

void solve(int nod, SegTree &st) {
    /*for(int i = 1; i <= 2 * n; i++) {
        cerr << st.query(1, 1, 2 * n, i, i) << " ";
    }
    cerr << "\n";*/
    for(auto it : qry[nod]) {
        auto itl = lower_bound(leaves.begin(), leaves.end(), it.l);
        auto itr = upper_bound(leaves.begin(), leaves.end(), it.r);
        itr--;
        sol[it.pos] = st.query(1, 1, 2 * n, idl[*itl], idr[*itr]);
    }
    for(auto it : g[nod]) {
        st.update(1, 1, 2 * n, idl[it.first], idr[it.first], -it.second);
        if(idl[it.first] > 1) {
            st.update(1, 1, 2 * n, 1, idl[it.first] - 1, it.second);
        }
        if(idr[it.first] < 2 * n) {
            st.update(1, 1, 2 * n, idr[it.first] + 1, 2 * n, it.second);
        }
        solve(it.first, st);
        st.update(1, 1, 2 * n, idl[it.first], idr[it.first], it.second);
        if(idl[it.first] > 1) {
            st.update(1, 1, 2 * n, 1, idl[it.first] - 1, -it.second);
        }
        if(idr[it.first] < 2 * n) {
            st.update(1, 1, 2 * n, idr[it.first] + 1, 2 * n, -it.second);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(i = 1; i <= n; i++) {
        leaf[i] = 1;
    }

    for(i = 2; i <= n; i++) {
        int par, w;
        cin >> par >> w;
        g[par].push_back({i, w});
        leaf[par] = 0;
    }

    for(i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        if(leaf[i]) {
            leaves.push_back(i);
        }
    }

    SegTree st;
    st.init(2 * n);

    int sz = 0;
    dfs(1, sz, st, 0);

    for(i = 1; i <= q; i++) {
        int nod, l, r;
        cin >> nod >> l >> r;
        qry[nod].push_back({l, r, i});
    }

    solve(1, st);

    for(i = 1; i <= q; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}