#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        long long n;
        cin >> n;
        if (n % 14 >= 1 && n % 14 <= 6 && n > 14) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }   
    return 0;
}