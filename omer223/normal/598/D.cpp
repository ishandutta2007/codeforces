#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const int sz = 1e3 + 5;
int n, m, k;
string b[sz];
int cr = 1;
int comp[sz][sz];
int cmps[sz * sz];

int dir[][2]{ {1,0},{-1,0},{0,1},{0,-1} };

inline bool in(int i, int j) {
    return(i >= 0 && i < n&& j >= 0 && j < m);
}

void dfs(int i, int j) {
    comp[i][j] = cr;
    foru(r, 0, 4) {
        int di = i + dir[r][0], dj = j + dir[r][1];
        if (!in(di, dj))continue;
        else if (b[di][dj] == '.') {
            if (!comp[di][dj])dfs(di, dj);
        }
        else cmps[cr]++;
    }
}

int main() {
    fast;
    cin >> n >> m >> k;
    foru(i, 0, n)cin >> b[i];
    foru(i, 0, n) {
        foru(j, 0, m) {
            if (b[i][j] != '.' || comp[i][j])continue;
            dfs(i, j);
            cr++;
        }
    }
    foru(i, 0, k) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << cmps[comp[x][y]] << '\n';
    }
    return 0;
}