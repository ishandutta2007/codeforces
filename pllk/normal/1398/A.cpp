#include <iostream>

using namespace std;

int n;
int a[101010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (a[1]+a[2] <= a[n]) {
            cout << 1 << " " << 2 << " " << n << "\n";
        } else {
            cout << "-1\n";
        }
    }
}