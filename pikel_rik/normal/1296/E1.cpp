#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 200 + 5;

int n, c[N];
string s;

vector<int> g[N];
bool ok = true;

void dfs(int x, int col) {
    if (c[x] != -1) {
        if (c[x] != col) {
            cout << "NO\n";
            exit(0);
        } else return;
    }

    c[x] = col;
    for (int &i : g[x]) {
        dfs(i, col ^ 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] < s[j]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; i++) {
        if (c[i] == -1) {
            dfs(i, 0);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << c[i]; cout << "\n";
    return 0;
}