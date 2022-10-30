#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <numeric>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;

const ll mod = 1e9 + 7;

const int sz = 5e2 + 1;
int dp[sz][sz], prv[sz][sz];
char a[sz][sz];
int n, m;
vector<pii> dist[2*sz];
int dir1[][2]{ {1,0},{0,1} };
int dir2[][2]{ {-1,0},{0,-1} };

int main() {
    fast;
    cin >> n >> m;
    foru(i, 0, n) {
        string s;
        cin >> s;
        foru(j, 0, m)a[i][j] = s[j], dist[i + j].push_back({ i,j });
    }
    int d = (n + m - 2);
    if (d & 1) {
        for (pii ii : dist[d / 2]) {
            int x = ii.ff, y = ii.ss;
            ford(z, n - 1, x) {
                int w = n - 1 - z + m - 1 - x - y;
                if (w < y || w >= m)continue;
                prv[x][z] = (a[x][y] == a[z][w]);
            }
        }
    }
    else {
        for (pii ii : dist[d/2]) {
            prv[ii.ff][ii.ff] = 1;
        }
    }
    ford(di, d / 2 - 1, 0) {
        for (pii ii : dist[di]) {
            int x = ii.ff, y = ii.ss;
            ford(z, n - 1, x) {
                int w = n - 1 - z + m - 1 - x - y;
                if (w < y || w >= m)continue;
                if (a[x][y] == a[z][w]) {
                    foru(r1, 0, 2) {
                        int nx = x + dir1[r1][0], ny = y + dir1[r1][1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                        foru(r2, 0, 2) {
                            int nz = z + dir2[r2][0], nw = w + dir2[r2][1];
                            if (nz < 0 || nz >= n || nw < 0 || nw >= m)continue;
                            if (nz < nx || nw < ny)continue;
                            dp[x][z] += prv[nx][nz];
                            dp[x][z] %= mod;
                        }
                    }
                }
            }
        }
        foru(i, 0, n) {
            foru(j, 0, n) {
                prv[i][j] = dp[i][j];
                dp[i][j] = 0;
            }
        }
    }
    cout << prv[0][n - 1];
    return 0;
}