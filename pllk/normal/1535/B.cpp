#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (gcd(a[i],2*a[j]) > 1) {
                    c++;
                } else {
                    if (a[i]%2 != 0 && a[j]%2 == 0) c++;
                }
            }
        }
        cout << c << "\n";
    }
}