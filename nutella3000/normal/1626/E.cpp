#include<bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }

mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7, mod = 1e9 + 7;
const int N = 3e5 + 3;

int n;
int cnt_all = 0;
int c[N], o[N], t[N], res[N];
vector<int> gr[N];

void predfs(int v, int pr) {
    o[v] = c[v]; bool sp = c[v];
    for (int to : gr[v]) {
        if (to == pr) continue;
        predfs(to, v);
        o[v] += o[to];
        t[v] |= t[to];
        sp |= c[to];
    }
    if (sp && o[v] > 1) t[v] = 1;
}

void dfs(int v, int pr, bool gif) {
    res[v] = gif | c[v] | t[v];
    for (int to : gr[v])
        if (c[to]) res[v] = 1;

    vector<int> ts, cs;
    for (int to : gr[v]) {
        if (to == pr) continue;
        if (t[to] && size(ts) < 2) ts.pb(to);
        if (c[to] && size(cs) < 2) cs.pb(to);
    }
    if (c[v]) cs.pb(v);
    for (int to : gr[v]) {
        if (to == pr) continue;
        int ng = gif;
        for (auto i : ts)
            if (i != to) ng = 1;
        /*if (to+1 == 5) {
            cout << cnt_all << " " << o[to] << endl;
        }*/
        if (cnt_all - o[to] > 1) {
            for (auto i : cs)
                if (i != to) ng = 1;
        }
        if (o[to] != o[v] && c[pr]) ng = 1;
        dfs(to, v, ng);
    }
}

void run() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        cnt_all += c[i];
    }
    for (int i = 0; i < n-1; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].pb(v2); gr[v2].pb(v1);
    }
    predfs(0, -1);
    dfs(0, -1, 0);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}