#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

char s1[100], s2[100];
bool used[50][50];
vector <pii> e[50][50];

void dfs(int x, int y) {
    if (used[x][y]) return;
    used[x][y] = true;
    for (int i = 0; i < e[x][y].size(); i++) {
        int tx = e[x][y][i].first;
        int ty = e[x][y][i].second;
        dfs(tx, ty);
    }
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    scanf("%s\n", s1);
    scanf("%s\n", s2);
    for (int i = 0; i < n; i++) {
        if (s1[i] == '>') for (int j = 0; j < m - 1; j++) e[i][j].push_back(make_pair(i, j + 1));
        else for (int j = 1; j < m; j++) e[i][j].push_back(make_pair(i, j - 1));
    }
    for (int j = 0; j < m; j++) {
        if (s2[j] == 'v') for (int i = 0; i < n - 1; i++) e[i][j].push_back(make_pair(i + 1, j));
        else for (int i = 1; i < n; i++) e[i][j].push_back(make_pair(i - 1, j));
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        memset(used, false, sizeof(used));
        dfs(i, j);
        for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) if (!used[x][y]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}