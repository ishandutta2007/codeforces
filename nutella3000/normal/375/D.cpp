#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int max_n = 1e5 + 5;
int bl = 300;

struct query {
    int l, r, k, id;
    query(int l, int r, int k, int id) : l(l), r(r), k(k), id(id) {}

    query() {}

    bool operator<(query a) {
        if (a.l / bl != l / bl)
            return l < a.l;
        if (a.r != r)
            return r < a.r;
        return id < a.id;
    }
};

int n;
vector<int> gr[max_n];
int old_c[max_n];

vector<int> c;
int in[max_n], out[max_n];

void dfs(int v, int pr) {
    in[v] = c.size();
    c.emplace_back(old_c[v]);

    for(int i : gr[v]) {
        if (i != pr)
            dfs(i, v);
    }

    out[v] = c.size();
    c.emplace_back(old_c[v]);
}

int res[2 * max_n];
int max_cnt = 0;
int col[max_n];
int l, r;
vector<query> q;

void scan() {
    int m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        cin >> old_c[i];

    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    dfs(0, -1);

    for(int i = 0;i < m;i++) {
        int v, k;
        cin >> v >> k;
        v--;
        q.emplace_back(in[v], out[v], 2 * k, i);
    }

    sort(q.begin(), q.end());
}

void add(int id) {
    col[c[id]]++;

    int t = col[c[id]];
    if (t > max_cnt) {
        res[t] = 0;
        max_cnt++;
    }
    res[t]++;
    
    /*for(int i = 0;i <= 2;i++) 
        cout << res[i] << " ";
    cout << endl;*/

    if (r < id) 
        r++;
    else 
        l--;
}

void remove(int id) {
    res[col[c[id]]]--;
    col[c[id]]--;

    if (l < id)
        r--;
    else 
        l++;
}


void solve() {
    scan();

    /*for(int i : c)
        cout << i << " ";

    cout << endl;
    for(int i = 0;i < n;i++) {
        cout << in[i] + 1 << " " << out[i] + 1 << endl;
    }*/
    //cout << endl;

    //cout << q[0].l << " " << q[0].r << " " << q[0].k << " " << q[0].id << endl;

    vector<int> q_res(q.size());


    int last_b = -1;
    for(auto v : q) {
        if (v.l / bl != last_b) {
            max_cnt = 0;
            for(int i = 0;i < max_n;i++) 
                col[i] = 0;
            //col.clear();
            l = v.l;
            r = v.l - 1;
        }
        last_b = v.l / bl;

        while(r < v.r)
            add(r + 1);

        while(l > v.l)
            add(l - 1);

        while(l < v.l)
            remove(l);

        q_res[v.id] = (v.k > max_cnt ? 0 : res[v.k]);
        //cout << v.id << " " << q_res[v.id] << endl;
    }

    for(int i : q_res) 
        cout << i << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}