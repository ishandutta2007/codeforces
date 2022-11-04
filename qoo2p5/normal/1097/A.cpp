#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

void run() {
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < 5; i++) {
        string t;
        cin >> t;
        if (s[0] == t[0]) ok = true;
        if (s[1] == t[1]) ok = true;
    }
    cout << (ok ? "YES" : "NO") << "\n";
}