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

void run() {
    string s;
    cin >> s;
    int v = 0, h = 1;
    for (char c : s) {
        if (c == '0') {
            if (v) {
                cout << "1 1\n";
            } else {
                cout << "3 1\n";
            }
            v ^= 1;
        } else {
            cout << h << " 3" << "\n";
            h++;
            if (h == 5) {
                h = 1;
            }
        }
    }
}