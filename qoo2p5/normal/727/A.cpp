#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

int run() {
    int a, b;
    cin >> a >> b;
    vector<int> ops;
    ops.push_back(b);
    
    while (b > a) {
        if (b % 2 == 0) {
            b /= 2;
            ops.push_back(b);
        } else if (b % 10 == 1) {
            b /= 10;
            ops.push_back(b);
        } else {
            break;
        }
    }
    
    if (a == b) {
        cout << "YES\n";
        reverse(ops.begin(), ops.end());
        cout << (int) ops.size() << "\n";
        for (int it : ops) {
            cout << it << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}