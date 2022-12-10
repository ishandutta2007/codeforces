//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int dx[] = {-1, -0, +0, +1};
int dy[] = {-0, -1, +1, +0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    char my;
    cin >> n >> m >> my;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    bool adj[26];
    memset(adj, 0, sizeof adj);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (s[i][j] == my) {
            for (int d = 0; d < 4; d++) {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (0 <= ii and ii < n and 0 <= jj and jj < m and s[ii][jj] != '.')
                    adj[s[ii][jj] - 'A'] = true;
            }
        }
    cout << count(adj, adj + 26, true) - adj[my - 'A'] << '\n';
    return 0;
}