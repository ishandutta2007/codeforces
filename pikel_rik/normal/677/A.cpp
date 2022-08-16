#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int c = 0;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > h)
            c += 2;
        else
            c += 1;
    }
    cout << c;
    return 0;
}