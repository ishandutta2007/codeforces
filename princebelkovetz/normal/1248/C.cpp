#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n, m; cin >> n >> m;
    vector <int> fib = { 1, 1 };
    for (int i = 2; i <= max(n, m); ++i){
        fib.push_back(fib.back() + fib[fib.size() - 2]);
        fib.back() %= mod;
    }
    cout << 2 * (fib[n] + fib[m] - 1) % mod;
    return 0;
}