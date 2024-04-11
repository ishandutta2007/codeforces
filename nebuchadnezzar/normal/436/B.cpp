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
const int MAXN = 2005;

int n, m, k;
int ans[MAXN];
string s;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'U') {
                if (!(i % 2)) {
                    ++ans[j];
                }
            }
            if (s[j] == 'R') {
                if (m - j > i) {
                    ++ans[j + i];
                }
            }
            if (s[j] == 'L') {
                if (j >= i) {
                    ++ans[j - i];
                }
            }
        }
    }     
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}