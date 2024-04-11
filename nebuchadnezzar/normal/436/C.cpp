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
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
const int MAXN = 15, MAXK = 1005, INF = 1e9;

int n, m, k, w;

char maps[MAXN][MAXN][MAXK];
int graph[MAXK][MAXK];
pair <int, int> nowlen[MAXK];
bool used[MAXK];
string s;
vector <pair <int, int> > ansm;

int main() {
    cin >> n >> m >> k >> w;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> s;
            for (int j2 = 0; j2 < m; ++j2) {
                maps[j][j2][i] = s[j2]; 
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            int c = 0;
            for (int i2 = 0; i2 < n; ++i2) {
                for (int j2 = 0; j2 < m; ++j2) {
                    if (maps[i2][j2][i] != maps[i2][j2][j]) {
                        ++c;
                    }
                }
            }
            graph[i][j] = c * w;
        }
    }                           
    for (int i = 0; i < k; ++i) {
        nowlen[i].ff = INF;
        graph[i][k] = n * m;
        graph[k][i] = n * m;
    }

    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        pair <pair <int, int>, int> nowmin = mapa(mapa(INF, 0), 0);
        for (int j = 0; j <= k; ++j) {
            if (!used[j]) {
                nowmin = min(nowmin, mapa(nowlen[j], j));
            }
        } 
        ansm.puba(mapa(nowmin.ss, nowmin.ff.ss));
        ans += nowmin.ff.ff;
        //cout << nowmin.ss << " " << nowmin.ff.ss << " " << nowmin.ff.ff << endl;
        used[nowmin.ss] = true;
        for (int j = 0; j <= k; ++j) {
            nowlen[j] = min(nowlen[j], mapa(graph[nowmin.ss][j], nowmin.ss));
        }
    }

    cout << ans << endl;
    for (int i = 1; i < szof(ansm); ++i) {
        cout << ansm[i].ff + 1 << " " << (ansm[i].ss + 1) % (k + 1) << endl;
    }
    return 0;
}