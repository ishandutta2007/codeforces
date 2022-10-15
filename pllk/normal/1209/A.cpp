#include <iostream>

using namespace std;

int n;
int a[111];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int c = 0;
    while (true) {
        int x = 333;
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0 && a[i] < x) x = a[i];
        }
        if (x == 333) break;
        c++;
        for (int i = 1; i <= n; i++) {
            if (a[i]%x == 0) a[i] = 0;
        }
    }
    cout << c << "\n";
}