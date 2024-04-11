#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int n, m;

vector<string> a;

bool cycle = false;
vector<vector<bool>> rstack(50, vector<bool> (50));

void dfs(int i, int j, int p1 = -1, int p2 = -1) {
    if (cycle) return;

    rstack[i][j] = true;

    if (i > 0 and a[i-1][j] == a[i][j] and (i - 1 != p1 or j != p2)) {
        if (rstack[i-1][j]) cycle = true;
        else dfs(i - 1, j, i, j);
    }
    if (j > 0 and a[i][j-1] == a[i][j] and (i != p1 or j - 1 != p2)) {
        if (rstack[i][j-1]) cycle = true;
        else dfs(i, j - 1, i, j);
    }
    if (i + 1 < n and a[i+1][j] == a[i][j] and (i + 1 != p1 or j != p2)) {
        if (rstack[i+1][j]) cycle = true;
        else dfs(i + 1, j, i, j);
    }
    if (j + 1 < m and a[i][j+1] == a[i][j] and (i != p1 or j + 1 != p2)) {
        if (rstack[i][j+1]) cycle = true;
        else dfs(i, j + 1, i, j);
    }

    rstack[i][j] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j);
            if (cycle) break;
        }
        if (cycle) break;
    }

    if (cycle) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}