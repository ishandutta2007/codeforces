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
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;

int n;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    
    if (n < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n % 2 == 0) {
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        for (int i = 5; i < n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n24 * 1 = 24\n";
        }
    } else {
        cout << "5 - 1 = 4\n4 - 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        for (int i = 6; i < n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n24 * 1 = 24\n";
        }
    }

    return 0;
}