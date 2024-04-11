#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;
const int MAXN = 25;

int n, m;

vector <pair <int, int> > graph[MAXN][MAXN];
bool used[MAXN][MAXN];
int num = 0;

int dfs(int x, int y) {
    //cout << x << " " << y << endl;
    used[x][y] = true;
    ++num;

    for (int i = 0; i < szof(graph[x][y]); ++i) {
        int nx = graph[x][y][i].ff;
        int ny = graph[x][y][i].ss;
        //cout << "try to " << nx << " " << ny << endl;
        if (!used[nx][ny]) {
            dfs(nx, ny);
        }
    }
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '>') {
            for (int j = 0; j < m - 1; ++j) {
                graph[i][j].puba(mapa(i, j + 1));
            }
        } else {
            for (int j = 1; j < m; ++j) {
                graph[i][j].puba(mapa(i, j - 1));
            }
        }
    }

    cin >> s;
    for (int i = 0; i < m; ++i) {
        if (s[i] == 'v') {
            for (int j = 0; j < n - 1; ++j) {
                graph[j][i].puba(mapa(j + 1, i));
            }
        } else {
            //cout << "@" << endl;
            for (int j = 1; j < n; ++j) {
                graph[j][i].puba(mapa(j - 1, i));
                //cout << j << " " << i << " " << j - 1 << " " << i << endl;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            memset(used, 0, sizeof used);
            num = 0;
            dfs(i, j);
            if (num != n * m) {
                cout << "NO\n";
                //cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "YES\n";

    return 0;
}