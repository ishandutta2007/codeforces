#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> v(n);

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j and v[j] == 0 and b[i] == a[j]) {
                v[j] = 1;
                c += 1;
            }
        }
    }

    cout << n - c;
    return 0;
}