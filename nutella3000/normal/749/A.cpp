#include<bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif

    int n;
    cin >> n;
    if (n % 2 == 0) cout << n / 2 << '\n';
    else cout << (n - 3) / 2 + 1 << '\n';
    while(n != 3 && n != 0) {
        cout << 2 << " ";
        n -= 2;
    }
    if (n == 3) cout << 3;
}