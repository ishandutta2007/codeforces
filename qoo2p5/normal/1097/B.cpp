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

const int N = 16;

int n, a[N];

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int s = 0;
        for (int i = 0; i < n; i++) if (mask & (1 << i)) s += a[i]; else s -= a[i];
        if (s % 360 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}