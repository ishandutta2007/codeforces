#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int n, m, k;
vector<string> maze;

vector<vector<bool>> visited;
int c = 0, emp = 1;

void dfs(int i, int j) {
    if (c == emp - k)
        return;

    visited[i][j] = true;
    c += 1;

    if (i > 0 and maze[i-1][j] == '.' and !visited[i-1][j]) dfs(i-1, j);
    if (j > 0 and maze[i][j-1] == '.' and !visited[i][j-1]) dfs(i, j-1);
    if (i+1 < n and maze[i+1][j] == '.' and !visited[i+1][j]) dfs(i+1, j);
    if (j+1 < m and maze[i][j+1] == '.' and !visited[i][j+1]) dfs(i, j+1);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    maze.resize(n);
    for (int i = 0; i < n; i++) cin >> maze[i];

    pi start = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                if (start.first == -1) {
                    start = {i, j};
                }
                else emp += 1;
            }
        }
    }

    visited.resize(n, vector<bool> (m));

    if (start.first != -1)
        dfs(start.first, start.second);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.' and !visited[i][j])
                maze[i][j] = 'X';
        }
    }

    for (int i = 0; i < n; i++) cout << maze[i] << "\n";


    return 0;
}