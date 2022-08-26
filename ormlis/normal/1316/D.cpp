#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

vector<vector<int>> table;
vector<vector<pair<int, int>>> xy;

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, 1, -1, 0};

int n;

void go(int c, int r, int t, pair<int, int> f) {
    if (c < 0 || c >= n || r < 0 || r >= n) return;
    if (table[c][r] == -1 && xy[c][r] == f) {
        table[c][r] = 3 - t;
        range(k, 4) {
            go(c + dx[k], r + dy[k], k, f);
        }
    }
}

bool dfs(int c, int r, int t) {
    if (c < 0 || c >= n || r < 0 || r >= n || xy[c][r].first != -1 || table[c][r] != -1) return false;
    table[c][r] = 3 - t;
    range(i, 4) {
        dfs(c + dx[i], r + dy[i], i);
    }
    return true;
}

void solve() {
    cin >> n;
    table.resize(n);
    xy.resize(n);
    range(i, n) {
        table[i].resize(n, -1);
        xy[i].resize(n);
        range(j, n) {
            cin >> xy[i][j].first >> xy[i][j].second;
            if (xy[i][j].first != -1) {
                xy[i][j].first--;
                xy[i][j].second--;
            }
        }
    }
    range(i, n) {
        range(j, n) {
            pair<int, int> f = {i, j};
            if (xy[i][j] == f) {
                go(i, j, 0, f);
                table[i][j] = 4;
            }
        }
    }
    range(i, n) {
        range(j, n) {
            if (xy[i][j].first != -1 && table[i][j] == -1) {
                cout << "INVALID";
                return;
            }
            if (xy[i][j].first == -1 && table[i][j] == -1) {
                range(k, 4) {
                    if (dfs(i + dx[k], j + dy[k], k)) {
                        table[i][j] = k;
                        break;
                    }
                }
                if (table[i][j] == -1) {
                    cout << "INVALID";
                    return;
                }
            }
        }
    }
    cout << "VALID\n";
    vector<char> ans = {'U', 'R', 'L', 'D', 'X'};
    range(i, n) {
        range(j, n) {
            cout << ans[table[i][j]];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}