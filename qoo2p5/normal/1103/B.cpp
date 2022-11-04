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
const ll MOD = (ll) (1e9 + 7);

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

int a;
int q;

int ask(int x, int y) {
    #ifdef LOCAL
        q++;
        return x % a < y % a;
    #else
        cout << "? " << x << " " << y << endl;
        string res;
        cin >> res;
        return res == "y";
    #endif
}

void answer(int x) {
    cout << "! " << x << endl;
}

void solve() {
    if (!ask(0, 1)) {
        answer(1);
        return;
    }
    int x = 1;
    while (2 * x <= 1000000000 && ask(x, 2 * x)) {
        x *= 2;
    }
    int left = x;
    int right = 2 * x;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (!ask(x, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    answer(right);
}

void run() {
    #ifdef LOCAL
    cin >> a;
    #endif
    string s;
    while (cin >> s) {
        if (s != "start") {
    #ifdef LOCAL
    cerr << q << endl;
    #endif
            return;
        }
        solve();
    }
}