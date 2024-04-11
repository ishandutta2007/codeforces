#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        map <char, int> ca, cb;
        for (int i = 0; i < 26; ++i)
            ca['a' + i] = 0, cb['a' + i] = 0;
        for (auto x : a)
            ca[x]++;
        for (auto x : b)
            cb[x]++;
        for (int i = 0; i < 25; ++i) {
            if (cb['a' + i] <= ca['a' + i] and (ca['a' + i] - cb['a' + i]) % k == 0) {
                ca['a' + i + 1] += ca['a' + i] - cb['a' + i];
                ca['a' + i] -= ca['a' + i] - cb['a' + i];
            }
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (ca['a' + i] != cb['a' + i])
                ok = false;
        }
        cout << (ok ? "Yes" : "No");
        cout << '\n';
    }
    return 0;
}