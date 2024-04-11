#include <iostream>

using namespace std;

int n, d;
int a[111];

void lol() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        while (a[i] > 0 && d >= i-1) {
            a[i]--;
            d -= i-1;
            a[1]++;
        }
    }
    cout << a[1] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}