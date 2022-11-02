#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

int main() {
    ll n;
    cin >> n;
    if (n == 1) cout << 4;
    else if (n <= 36) {
        cout << 8;
        if (n % 2 == 1) cout << 0;
        for (int i = 1; i < n / 2; ++i) cout << 8;
    } else cout << -1;
    return 0;
}