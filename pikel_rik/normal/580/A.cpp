#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = 0, c = 0;
    vector<int> diff(n, 0);

    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i-1];
    }
    for (int i = 0; i < n; i++) {
        if (diff[i] < 0)
            c = 1;
        else
            c += 1;
        if (c > m)
            m = c;
    }

    cout << m;
    return 0;
}