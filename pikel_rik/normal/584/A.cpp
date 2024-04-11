#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    if (t == 10)
        a[0] = 1;
    else
        a[0] = t;

    if (n == 1 and t == 10)
        cout << "-1";
    else {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
    }
    return 0;
}