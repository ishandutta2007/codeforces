#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);
    vector<int> a(6);
    int n;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        a[i] = (n >> i) & 1;
    }
    vector<int> b(6);
    b[0] = a[4];
    b[1] = a[1];
    b[2] = a[3];
    b[3] = a[2];
    b[4] = a[0];
    b[5] = a[5];
    int res = 0;
    for (int i = 0; i < 6; i++) {
        res += b[i] << i;
    }
    cout << res << "\n";
    return 0;
}