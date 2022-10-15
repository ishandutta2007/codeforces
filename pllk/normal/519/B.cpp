#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<int> c;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    b.resize(n-1);
    for (int i = 0; i < n-1; i++) cin >> b[i];
    c.resize(n-2);
    for (int i = 0; i < n-2; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    bool ok = false;
    for (int i = 0; i < n-1; i++) {
        if (a[i] != b[i]) {
            cout << a[i] << "\n";
            ok = true;
            break;
        }
    }
    if (!ok) cout << a[n-1] << "\n";
    ok = false;
    for (int i = 0; i < n-2; i++) {
        if (b[i] != c[i]) {
            cout << b[i] << "\n";
            ok = true;
            break;
        }
    }
    if (!ok) cout << b[n-2] << "\n";
}