#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int max_n = 1e3 + 3;

int xdir[]{1, -1, 0, 0};
int ydir[]{0, 0, 1, -1};

int max_sz = 0;
pii id_max;

struct dsu {
    vector<vector<pii>> p;
    vector<vector<int>> sz;

    dsu(int n, int m) {
        p.resize(n, vector<pii>(m));
        sz.resize(n, vector<int>(m));

        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                p[i][j] = {i, j}; 
    }

    pii get(pii v) {
        pii st = v;
        while(v != p[v.first][v.second]) 
            v = p[v.first][v.second];

        while(st != v) {
            pii t = p[st.first][st.second];
            p[st.first][st.second] = v;
            st = t;
        }
        return v;
    }

    void merge(pii v1, pii v2) {
        v1 = get(v1);
        v2 = get(v2);
        if (v1 == v2) 
            return;
        sz[v2.first][v2.second] += sz[v1.first][v1.second];
        p[v1.first][v1.second] = v2;
    }

    void upd(int v_x, int v_y) {
        sz[v_x][v_y] = 1;

        for(int i = 0;i < 4;i++) {
            int to_x = v_x + xdir[i];
            int to_y = v_y + ydir[i];

            if (to_x < 0 || to_y < 0 || to_x >= p.size() || to_y >= p[0].size() || sz[to_x][to_y] == 0)
                continue;

            merge({to_x, to_y}, {v_x, v_y});
        }

        if (max_sz < sz[v_x][v_y]) {
            max_sz = sz[v_x][v_y];
            id_max = {v_x, v_y};
        }
    }
};

int n, m;
int a[max_n][max_n];
map<int, vector<pii>> b;
bool used[max_n][max_n];

void solve() {
    int k;
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
            b[-a[i][j]].emplace_back(i, j);
        }
    }

    dsu c = dsu(n, m);

    for(auto temp : b) {
        max_sz = -1;
        int num = -temp.first;

        for(auto i : temp.second) {
            a[i.first][i.second] = 0;
            c.upd(i.first, i.second);
        }

        if (k % num != 0 || k / num > max_sz)
            continue;

        int cnt = k / num - 1;

        deque<pii> bfs;
        bfs.emplace_back(id_max);
        used[id_max.first][id_max.second] = true;

        while(bfs.size()) {
            pii v = bfs.front();
            bfs.pop_front();

            for(int i = 0;i < 4;i++) {
                pii to = {v.first + xdir[i], v.second + ydir[i]};

                if (to.first < 0 || to.second < 0 || to.first >= n || to.second >= m || used[to.first][to.second] || a[to.first][to.second] != 0)
                    continue;

                if (cnt == 0) 
                    break;
                
                cnt--;
                bfs.emplace_back(to);
                used[to.first][to.second] = true;
            }
        }

        cout << "YES" << endl;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {

                if (a[i][j] != 0 || !used[i][j])
                    cout << 0 << " ";
                else
                    cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    cout << "NO";
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}