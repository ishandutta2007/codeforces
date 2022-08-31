#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1500 + 5;

int n, m;
string a[N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> first[N][N];
bitset<2*3*N> visited[2*3*N];
const int Z = 3*N;

void bfs(int xx, int yy) {
    queue<pair<int, int>> q;
    q.emplace(xx, yy);

    visited[xx][yy] = true;
    first[xx][yy] = {xx, yy};

    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int new_x = x + dx[k], new_y = y + dy[k];
            if (visited[(new_x % n + n) % n][(new_y % m + m) % m] and first[(new_x % n + n) % n][(new_y % m + m) % m] != make_pair(new_x, new_y)) {
                cout << "Yes\n";
                exit(0);
            }
            if (!visited[(new_x % n + n) % n][(new_y % m + m) % m] and a[(new_x % n + n) % n][(new_y % m + m) % m] != '#') {
                q.emplace(new_x, new_y);
                visited[(new_x % n + n) % n][(new_y % m + m) % m] = true;
                first[(new_x % n + n) % n][(new_y % m + m) % m] = make_pair(new_x, new_y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                bfs(i, j);
                break;
            }
        }
    }

    cout << "No\n";
    return 0;
}