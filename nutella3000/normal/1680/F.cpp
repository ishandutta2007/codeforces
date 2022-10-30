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
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e15 + 7;
const int N = 1e6 + 3;

int n, m;
vector<int> gr[N];
int col[N], h[N], used[N], F1[N], F2[N];
int cnt_bad = 0, bad_v = -1;

void dfs(int v, int vc) {
    //cout << "dfs " << v+1 << endl;
    used[v] = true; col[v] = vc;

    for (int to : gr[v]) {
        if (!used[to]) {
            h[to] = h[v] + 1;
            dfs(to, 1-vc);
            F1[v] += F1[to];
            F2[v] += F2[to];

        } else if (h[to] < h[v]-1) {
            if (col[to] == col[v]) {
                ++F1[v], --F1[to];
                ++cnt_bad;
                bad_v = v;
            } else
                ++F2[v], --F2[to];
        }
    }
}
void fix(int v) {
    used[v] = true; col[v] = 1-col[v];
    for (int to : gr[v])
        if (!used[to] && h[to] > h[v]) fix(to);
}

void init() {
    cin >> n >> m;
    
    fill(col, col + n, 0);
    fill(h, h + n, 0);
    fill(used, used+n, 0);
    fill(F1, F1+n, 0);
    fill(F2, F2+n, 0);
    cnt_bad = 0, bad_v = -1;
    for (int i = 0; i < n; ++i)
        gr[i].clear();


    for (int i = 0; i < m; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].eb(v2);
        gr[v2].eb(v1);
    }
}

void run() {
    init();
    dfs(0, 0);
    fill(used, used+n, 0);

    int del_v = -1;
    for (int i = 0; i < n; ++i) {
        if (F1[i] == cnt_bad && !F2[i]) del_v = i;
    }
    if (cnt_bad > 1 && del_v == -1) {
        cout << "NO" << '\n';
        return;
    }

    if (del_v != -1) {
        fix(del_v);
        bad_v = del_v;
    }
    if (bad_v != -1 && !col[bad_v]) {
        for (int i = 0; i < n; ++i)
            col[i] = 1 - col[i];
    }
    for (int v1 = 0; v1 < n; ++v1) {
        for (int v2 : gr[v1]) {
            if (!col[v1] && !col[v2]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i)
        cout << col[i];
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}