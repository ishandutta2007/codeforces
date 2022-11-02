#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_n = 1e6 + 3;

int n;
vector<int> gr[max_n];
int a[max_n];

struct dsu {
    vector<int> par, sz;

    dsu() {
        par.resize(n);
        sz.resize(n, 0);
        iota(all(par), 0);
    }

    int get(int v) {
        int s = v;
        while(par[v] != v) v = par[v];

        while(s != v) {
            int t = par[s];
            par[s] = v;
            s = t;
        }
        return v;
    }

    void merge(int v1, int v2) {
        if (v1 == v2) {
            sz[v1] = 1;
            return;
        }

        v1 = get(v1); v2 = get(v2);

        if (sz[v1] == 0 || sz[v2] == 0) return;

        if (v1 == v2) return;
        par[v1] = v2;
        sz[v2] += sz[v1];
    }
};

int solve(vector<int> id) {

    dsu b = dsu();

    int res = 0;

    for(int v : id) {
        vector<int> temp;
        b.merge(v, v);
        for(int to : gr[v]) {
            temp.emplace_back(b.sz[b.get(to)]);
            b.merge(v, to);
        }

        int cnt = 0;
        for(int i = 0;i < sz(temp);i++) {
            cnt += temp[i];
        }
        cnt *= cnt;
        for(int i : temp) {
            cnt -= i * i;
        }
        cnt /= 2;
        for(int i : temp) 
            cnt += i;

        //cout << v << " " << cnt << endl;
        res += cnt * a[v];

    }

    return res;
}


void solve() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    vector<int> id(n);
    iota(all(id), 0);

    sort(all(id), [a](int v1, int v2) {return a[v1] < a[v2];});

    int res1 = solve(id);

    reverse(all(id));

    int res2 = solve(id);

    cout << res1 - res2;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}