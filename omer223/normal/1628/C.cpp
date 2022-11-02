#define _CRT_SECURE_NO_WARNINGS
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

int dir[][2]{ {-1,0},{0,1},{0,-1} };

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0)), b = a;
    foru(i, 0, n) {
        foru(j, 0, n)cin >> a[i][j];
    }
    int cr = 0;
    foru(i, 1, n) {
        foru(j, 0, n) {
            int tmp = 0;
            foru(r, 0, 3) {
                int mi = i - 1 + dir[r][0], mj = j + dir[r][1];
                if (mi < 0 || mi >= n || mj < 0 || mj >= n)continue;
                tmp ^= b[mi][mj];
            }
            b[i][j] = tmp ^ a[i-1][j];
            cr ^= b[i][j];
        }
    }
    cout << cr << '\n';
}

int main() {
    fast;
	
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}