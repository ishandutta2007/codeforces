#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
long long a[(int)2e5 +9];
int main() {
    long long n; cin >> n;
    for (int i = 0; i <n; ++i) {
        int x; cin >> x; a[x] = i+1;
    }
    long long mx = 0;
    for (int i = 0;i< n; ++i) {
        int y; cin >> y;
        if (a[y] > mx) {
            cout << a[y] - mx << endl; mx = a[y];
        } else cout << 0 << endl;
    }
}