#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1001;
const int cons = 2520;
int n, k[max_n];
vector<int> gr[max_n * cons];
int res[max_n * cons];
int used[max_n * cons];
vector<int> vertex;

bool dfs(int v) {
    if (used[v] == 1) {
        vertex.emplace_back(v);
        return true;
    }
    if (used[v] == 2) return false;
    used[v] = 1;
    vertex.emplace_back(v);
    for (int to : gr[v]) {
        if (dfs(to)) {
            used[v] = 2;
            return true;
        }
        if (used[to] == 2) res[v] = res[to];
    }
    used[v] = 2;
    vertex.pop_back();
    return false;
}

void scan() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> k[i];
    for (int v = 0; v < n; v++) {
        int temp2;
        cin >> temp2;
        for (int temp = 0; temp < temp2; temp++) {
            int to;
            cin >> to;
            to--;

            for (int i = 0; i < cons; i++) {
                int fuck = (((i + k[v]) % cons + cons) % cons);
                if (fuck % temp2 == temp) {
                    gr[i * n + v].emplace_back(fuck * n + to);
                }
            }
        }
    }

    bool apper[n];
    for (int i = 0; i < n; i++) apper[i] = false;

    for (int i = 0; i < cons * n; i++) {
        if (used[i] == 0) {
            if (!dfs(i)) {
                if (!vertex.empty()) n /= 0;
            } else {
                if (vertex.empty()) continue;
                vector<int> temp;
                while (vertex[0] != vertex.back()) {
                    temp.emplace_back(vertex[0]);
                    vertex.erase(vertex.begin());
                }
                vertex.erase(vertex.begin());
                int num = 0;

                for (int j : vertex) {
                    if (!apper[j % n]) {
                        apper[j % n] = true;
                        num++;
                    }
                }

                for (int j : vertex)
                    apper[j % n] = false;

                for (int j : vertex) res[j] = num;
                vertex.clear();

                for (int j : temp) res[j] = num;
            }
        }
    }
}

void solve() {
    scan();
    int q;
    cin >> q;
    for (; q > 0; q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y = (y % cons + cons) % cons;
        cout << (res[y * n + x]) << '\n';
    }

}


signed main() {
    //freopen("search4.in", "r", stdin);
    //freopen("search4.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
}