#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
 mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 200005;

vector<int> g[N];
ull fu[N];
int fib[N];

ull total_val = 0;

int as[2], bs[2];
int s_ind = 0;
int siz[N];
int cur_x = 0;

unordered_map<ull, bool> q;

void dfs(int v, int pr) {
    total_val ^= fu[v];
    siz[v] = 1;
    for (int u : g[v]) {
        if (u != pr) {
            dfs(u, v);
            if (siz[u] == fib[cur_x - 1] || siz[u] == fib[cur_x - 2]) {
                as[s_ind] = v;
                bs[s_ind] = u;
                s_ind++;
            }
            siz[v] += siz[u];
        }
    }
}

bool find(int v, int x) {
    if (x <= 4) {
        return true;
    }
    cur_x = x;
    total_val = 0;
    s_ind = 0;
    dfs(v, -1);
    if (q.count(total_val)) {
        return q[total_val];
    }
    if (s_ind == 2) {
        if ((fu[v] ^ fu[as[0]]) > (fu[v] ^ fu[as[1]])) {
            swap(as[0], as[1]);
            swap(bs[0], bs[1]);
        }
    }
    for (int i = 0; i < s_ind; i++) {
        int A = as[i], B = bs[i];
        int i1 = 0;
        while (g[A][i1] != B) {
            i1++;
        }
        if (sz(g[A]) > 1) {
            swap(g[A][i1], g[A][sz(g[A]) - 1]);
        }
        g[A].pop_back();

        int i2 = 0;
        while (g[B][i2] != A) {
            i2++;
        }
        if (sz(g[B]) > 1) {
            swap(g[B][i2], g[B][sz(g[B]) - 1]);
        }
        g[B].pop_back();
        int fir = x - 1, sec = x - 2;
        if (siz[B] == fib[x - 1]) {
            swap(fir, sec);
        }
        if ((fu[v] ^ fu[A]) > (fu[v] ^ fu[B])) {
            swap(A, B);
            swap(fir, sec);
        }
        if (find(A, fir)) {
            if (find(B, sec)) {
                q[total_val] = true;
                return true;
            }
        }
        g[A].push_back(B);
        g[B].push_back(A);
    }
    q[total_val] = false;
    return false;
}

int solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    fib[1] = fib[2] = 1;
    for (int i = 3;; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > N) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        shuffle(g[i].begin(), g[i].end(), rnd);
    }
    int x = 1;
    while (fib[x] != n) {
        x++;
    }
    if (fib[x] != n) {
        cout << "NO\n";
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fu[i] = rnd();
    }
    int xxx = rnd();
    xxx = abs(xxx);
    q.rehash(20000000);
    if (find(xxx % n, x)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 1;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}