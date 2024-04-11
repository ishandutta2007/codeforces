#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1440];

    memset(a, 0, sizeof(a));

    int h, m;
    for (int i = 0; i < n; i++) {
        cin >> h >> m;
        a[h * 60 + m] += 1;
    }

    cout << *max_element(a, a + 1440);
    return 0;
}