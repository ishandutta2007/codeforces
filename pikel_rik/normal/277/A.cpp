#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

vector<int> g[101];
vector<bool> visited(101);

void bfs(int x) {
    queue<int> q;
    q.push(x);

    visited[x] = true;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int i : g[a]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1);
    int temp = 0;

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        a[i].resize(k);

        temp += (k == 0);

        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            for (int idx = 1; idx < i; idx++) {
                for (int y : a[idx]) {
                    if (a[i][j] == y) {
                        g[i].push_back(idx);
                        g[idx].push_back(i);
                        break;
                    }
                }
            }
        }
    }

    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] and !a[i].empty()) {
            bfs(i);
            c += 1;
        }
    }

    cout << (c > 0 ? c - 1 : 0) + temp << "\n";
    return 0;
}