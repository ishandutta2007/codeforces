#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    b.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    vector<int> c;
    c.resize(n - 2);
    for (int i = 0; i < n - 2; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << a[i] << "\n";
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] != c[i]) {
            cout << b[i] << "\n";
            break;
        }
    }
    return 0;
}