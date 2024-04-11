#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int c = 0;
    vector<int> count(n+1);

    for (int i = 0; i < n; i++) {
        if (a[i] > n)
            c += 1;
        else
            count[a[i]] += 1;
    }

    for (int i = 1; i <= n; i++) {
        if (count[i] > 1)
            c += count[i] - 1;
    }

    cout << c;
    return 0;
}