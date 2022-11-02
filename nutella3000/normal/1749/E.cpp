#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const int N = 2e5 + 3;

int n, m;
vector<string> s;



bool check(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}


int dx1[]{0, 1, 0, -1};
int dy1[]{1, 0, -1, 0};

int cock(int i, int j) {
    if (!check(i, j)) return inf;
    for (int d = 0; d < 4; ++d) {
        int x = i + dx1[d], y = j + dy1[d];
        if (check(x, y) && s[x][y] == '#') return inf;
    }
    return s[i][j] != '#';
}

int dx2[]{1, 1, -1, -1};
int dy2[]{1, -1, -1, 1};

pair<int, vector<string>> bfs(bool odd) {
    vector dist(n, vector<int>(m, inf));
    vector pred(n, vector<pair<int, int>>(m, {-1, -1}));

    deque<pair<int, int>> bfs;

    for (int i = odd; i < n; i += 2) {
        if ((dist[i][0] = cock(i, 0)) != inf) {
            if (cock(i, 0)) {
                bfs.push_back({i, 0});
            } else {
                bfs.push_front({i, 0});
            }
        }
    }
    int res_x = -1, res_y = -1;
    while (size(bfs)) {
        auto [i, j] = bfs.front();
        if (j == m-1) {
            res_x = i, res_y = j; break;
        }

        bfs.pop_front();

        for (int d = 0; d < 4; ++d) {
            int x = i + dx2[d], y = j + dy2[d];
            if (check(x, y) && chmin(dist[x][y], dist[i][j] + cock(x, y))) {
                if (cock(x, y)) {
                    bfs.push_back({x, y});
                } else {
                    bfs.push_front({x, y});
                }
                pred[x][y] = {i, j};
            }
        }
    }
    vector<string> a = s;
    if (res_x == -1) return {inf, a};

    int res = dist[res_x][res_y];

    while (res_x != -1) {
        a[res_x][res_y] = '#';
        auto [x, y] = pred[res_x][res_y];
        res_x = x, res_y = y;
    }
    return {res, a};
}

void run() {
    cin >> n >> m;
    s.assign(n, "");
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    auto [r1, ans1] = bfs(0);
    auto [r2, ans2] = bfs(1);
    if (r2 < r1) {
        swap(r1, r2);
        swap(ans1, ans2);
    }
    if (r1 >= inf) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES" << '\n';
        for (auto i : ans1)
            cout << i << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}