#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 51;
int a[N][N];
int res;

int q(int ax, int ay, int bx, int by) {
    cout << "? " << ax + 1 << ' ' << ay + 1 << ' ' << bx + 1 << ' ' << by + 1 << endl;
    cin >> res;
    return res;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
	int n;
    cin >> n;
    a[0][0] = 1;
    a[2][1] = q(1, 0, 2, 1) ^ 1;
    a[0][1] = a[2][1] ^ q(0, 1, 2, 1) ^ 1;
    rep(i, n)
        rep(j, n) {
            if (i + j <= 1 || i == 2 && j == 1 || i == n - 1 && j == n - 1)
                continue;
            if (i == 0)
                a[i][j] = a[i][j - 2] ^ q(i, j - 2, i, j) ^ 1;
            else if (j == 0)
                a[i][j] = a[i - 2][j] ^ q(i - 2, j, i, j) ^ 1;
            else
                a[i][j] = a[i - 1][j - 1] ^ q(i - 1, j - 1, i, j) ^ 1;
        }
    int f = -1;
    rep(i, n - 1) {
        rep(j, n - 1) {
            if (i < n - 2) {
                if (a[i + 1][j] == a[i][j + 1] && a[i + 1][j + 1] == a[i + 2][j] && (a[i][j] == a[i + 2][j + 1]) != (a[i][j + 1] == a[i + 1][j + 1]))
                    continue;
                f = q(i, j, i + 2, j + 1) ^ (a[i][j] == a[i + 2][j + 1]);
                break;
            }
            if (j < n - 2) {
                if (a[i][j + 1] == a[i + 1][j] && a[i + 1][j + 1] == a[i][j + 2] && (a[i][j] == a[i + 1][j + 2]) != (a[i + 1][j] == a[i + 1][j + 1]))
                    continue;
                f = q(i, j, i + 1, j + 2) ^ (a[i][j] == a[i + 1][j + 2]);
                break;
            }
        }
        if (f >= 0)
            break;
    }
    assert(f >= 0);
    if (f)
        rep(i, n)
            rep(j, n)
                a[i][j] ^= ((i + j) % 2);
    cout << "!" << endl;
    rep(i, n) {
        rep(j, n)
            cout << a[i][j];
        cout << endl;
    }
}