#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int l = *min_element(a.begin(), a.end()), r = *max_element(b.begin(), b.end());

    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == l and b[i] == r) {
            pos = i + 1;
            break;
        }
    }
    cout << pos;

    return 0;
}