#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll c[100];

int main() {
    c[1] = 2;
    for (int i = 2; i < 60; i++) {
        c[i] = c[i-1]+(1LL<<i);
    }
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        if (x%2 == 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> v;
        v.push_back(1);
        x -= 2;
        for (int i = 59; i >= 1; i--) {
            while (x >= c[i]) {
                x -= c[i];
                for (int j = 0; j < i-1; j++) v.push_back(0);
                v.push_back(1);
            }
        }
        cout << v.size() << "\n";
        for (auto a : v) cout << a << " ";
        cout << "\n";
    }
}