#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, a, b; cin >> n >> a >> b;
    --a, --b;
    for (int i = 19; i >= 0; --i) {
        if ((a >> i) % 2 != (b >> i) % 2) {
            if ((2 << i) == n) cout << "Final!\n";
            else cout << i + 1 << '\n';
            return 0;
        }
    }


    return 0;
}