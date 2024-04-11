#include <iostream>

using namespace std;

int a[202020];

void lol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) {
        if (abs(a[i]-a[i+1]) > 1) {
            cout << "YES\n";
            cout << i << " " << i+1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}