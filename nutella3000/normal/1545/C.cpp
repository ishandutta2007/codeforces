#include <bits/stdc++.h>
using namespace std;
     
//#define _GLIBCXX_DEBUG
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
    
mt19937 rnd;
int rand(int a) { return (rnd() % a + a) % a; }
 
const int inf = 1e15 + 2, mod = 998244353;
const int max_n = 501;

int n;
bool ban[2 * max_n], goodban[2 * max_n];
vector<int> gr[4 * max_n];

void add_edge(int v1, int v2) {
    gr[v1].pb(v2), gr[v2].pb(v1);
}


bool used[4 * max_n];

void dfs(int v, vector<int>& st) {
    if (used[v]) return;
    used[v] = true;
    st.pb(v);
    for (int to : gr[v])
        dfs(to, st);
}


void run() {
    cin >> n;

    for (int i = 0; i < 2 * n; ++i)
        ban[i] = false, goodban[i] = false;
    for (int i = 0; i < 4 * n; ++i)
        gr[i].clear();

    vector<vector<int>> a(2 * n, vector<int>(n));
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }


    for (int it = 0; it < n; ++it) {
        /*cout << it << endl;
        for (int i = 0; i < 2 * n; ++i)
            cout << ban[i] << " ";
        cout << endl;*/
        for (int i = 0; i < n; ++i) {
            vector<int> el(n, -1);
            for (int j = 0; j < 2 * n; ++j) {
                if (ban[j]) continue;
                if (el[a[j][i]] != -1) el[a[j][i]] = inf;
                else el[a[j][i]] = j;
            }
            int v = -1;
            for (int q = 0; q < n; ++q)
                if (el[q] >= 0 && el[q] < 2 * n) v = el[q];
            //if (it == 4) cout << el[1] << endl;
            if (v != -1) {
                ban[v] = goodban[v] = true;
                for (int to = 0; to < 2 * n; ++to) {
                    if (ban[to]) continue;
                    bool good = false;
                    for (int q = 0; q < n; ++q)
                        if (a[v][q] == a[to][q]) good = true;
                    if (good) ban[to] = true;
                }
                break;
            }
        }
    }
flag:
    /*for (int i = 0; i < 2 * n; ++i)
        cout << ban[i] << " ";
    cout << endl;*/
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> el(n);
        for (int j = 0; j < 2 * n; ++j) {
            if (ban[j]) continue;
            el[a[j][i]].pb(j);
        }
        for (int j = 0; j < n; ++j) {
            if (size(el[j]) == 0) continue;
            if (size(el[j]) != 2) {
                cout << "el bad" << endl;
                exit(1);
            }
            add_edge(el[j][0], el[j][1] + 2 * n);
            add_edge(el[j][0] + 2 * n, el[j][1]);
        }
    }

    fill(used, used + 4 * n, 0);
    vector<vector<int>> cmp;
    for (int i = 0; i < 4 * n; ++i) {
        if (ban[i % (2 * n)]) continue;
        if (!used[i]) {
            cmp.pb();
            dfs(i, cmp.back());
        }
    }
    for (int i = 0; i < size(cmp); ++i) {
        sort(all(cmp[i]));
        /*for (int j : cmp[i])
            cout << j + 1 << " ";
        cout << endl;*/
    }

    int res = 1;
    for (int i = 0; i < size(cmp) / 2; ++i)
        res = res * 2 % mod;

    cout << res << endl;

    set<int> kek;

    for (int i = 0; i < size(cmp); ++i) {
        bool bad = false;
        for (int j : cmp[i])
            if (kek.count(j % (2 * n)) || kek.count(j % (2 * n) + 2 * n)) bad = true;
        if (!bad) {
            for (int j : cmp[i])
                kek.insert(j);
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (goodban[i]) kek.insert(i);
    }

    for (int i : kek) {
        if (i >= 2 * n) break;
        cout << i + 1 << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
     
    clock_t time = clock();

    int t = 1;
    cin >> t;
    while(t--) {
        run();
    }
}