#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> x;

bool ok(int u) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        if (i < u) s += 5;
        else s += x[i];
    }
    s /= n;
    return s >= 4.5;
}

int main() {
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(),x.end());
    for (int u = 0; u <= n; u++) {
        if (ok(u)) {
            cout << u << "\n";
            return 0;
        }
    }
}