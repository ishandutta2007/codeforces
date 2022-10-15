#include <iostream>

using namespace std;

int n;
int a[555];
int c;

int main() {
    cin >> n;
    for (int i = 1; i <= 2*n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 1; j <= 2*n; j++) {
            if (k == 0) {
                if (a[j] != 0) k = j;
            } else {
                if (a[j] == a[k]) {
                    a[j] = a[k] = 0;
                    break;
                } else if (a[j] != 0) {
                    c++;
                }
            }
        }
    }
    cout << c << "\n";
}