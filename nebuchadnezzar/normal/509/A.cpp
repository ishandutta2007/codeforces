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
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;

LL table[15][15];
int n;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    cin >> n;

    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0) {
                table[i][j] = 1;
            } else {
                table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
            ans = max(ans, table[i][j]);
        }
    }
    cout << ans;
    
    return 0;
}