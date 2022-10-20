#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100;

struct BIT {
    int tree[N * 2];
    void Set(int x, int val) {
        while(x < N * 2) {
            tree[x] += val;
            x += (x & -x);
        }
    }
    int Get(int x) {
        int ans = 0;
        while(x) {
            ans += tree[x];
            x -= (x & -x);
        }
        return ans;
    }
} Odd, Even;

int n, m, cnt = 0;
int lv[N], in[N], out[N], Init[N];
vector <int> a[N];

void DFS(int u, int p) {
    in[u] = ++cnt;
    lv[u] = lv[p] + 1;
    for(int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if(v != p)
            DFS(v, u);
    }
    out[u] = ++cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> Init[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1, 0);
    while(m--) {
        int type, x, val;
        cin >> type >> x;
        if(type == 1) {
            cin >> val;
            if(lv[x] & 1) {
                Odd.Set(in[x], val);
                Odd.Set(out[x] + 1, -val);
                Even.Set(in[x], -val);
                Even.Set(out[x] + 1, val);
            } else {
                Even.Set(in[x], val);
                Even.Set(out[x] + 1, -val);
                Odd.Set(in[x], -val);
                Odd.Set(out[x] + 1, val);
            }
        } else {
            if(lv[x] & 1) cout << Init[x] + Odd.Get(out[x]) << endl;
            else cout << Init[x] + Even.Get(out[x]) << endl;
        }
    }
    return 0;
}