#include <bits/stdc++.h>
using namespace std;
const int maxN = 100;
string s[maxN + 10];
int n, d[maxN + 10];
vector<int> g[maxN + 10];
int q[maxN + 10], qCnt;

void AddEdge(int u, int v) {
    g[u].push_back(v); ++d[v];
}

void TopSort() {
    for (int i = 1; i <= 26; ++i)
        if (!d[i]) q[++qCnt] = i;
    for (int i = 1; i <= 26; ++i)
        if (i > qCnt) {
            printf("Impossible"); return;
        } else {
            int p = q[i];
            for (int i = 0; i < g[p].size(); ++i) {
                int e = g[p][i];
                if (!--d[e]) q[++qCnt] = e;
            }
        }
    for (int i = 1; i <= 26; ++i) printf("%c", q[i] + 'a' - 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i < n; ++i) {
        int p = 0;
        while (p < s[i].size() && p < s[i + 1].size() && s[i][p] == s[i + 1][p])
            ++p;
        if (p == s[i + 1].size()) {
            printf("Impossible"); return 0;
        }
        if (p < s[i].size() && p < s[i + 1].size()) {
            AddEdge(s[i][p] - 'a' + 1, s[i + 1][p] - 'a' + 1);
        }
    }
    TopSort();
}