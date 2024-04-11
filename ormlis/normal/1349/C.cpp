#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 1000;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

bool t[maxN][maxN];
int s[maxN][maxN];

int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    range(i, n) range(j, m) {
        char x; cin >> x;
        if (x == '1') t[i][j] = true;
    }
    deque<pair<int, int>> qu;
    range(i, n) {
        range(j, m) {
            s[i][j] = INFi;
            range(w, 4) {
                int newi = i + di[w];
                int newj = j + dj[w];
                if (newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
                if (t[newi][newj] == t[i][j]) {
                    qu.push_back({i, j});
                    s[i][j] = 0;
                    break;
                }
            }
        }
    }
    while(!qu.empty()) {
        auto p = qu.front();
        qu.pop_front();
        int i = p.first;
        int j = p.second;
        range(w, 4) {
            int newi = i + di[w];
            int newj = j + dj[w];
            if (newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
            if (s[newi][newj] > s[i][j] + 1) {
                qu.push_back({newi, newj});
                s[newi][newj] = s[i][j] + 1;
            }
        }
    }
    range(_, q) {
        int i, j; ll p; cin >> i >> j >> p;
        i--; j--;
        bool ans;
        if (s[i][j] == INFi) {
            ans = t[i][j];
        } else {
            ll x = p - s[i][j];
            if (x < 0) ans = t[i][j];
            else ans = t[i][j] ^ (x&1);
        }
        if (ans) cout << "1\n";
        else cout << "0\n";
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