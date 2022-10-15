#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[101010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    bool ok = true;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) ok = false;
    }
    if (ok) {
        cout << "yes\n";
        cout << "1 1\n";
        return 0;
    }
    int u1, u2;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            int k = i;
            for (int j = i+1; j < n-1; j++) {
                if (a[j] < a[j+1]) break;
                k = j;
            }
            u1 = i+1;
            u2 = k+2;
            reverse(a+i, a+k+2);
            break;
        }
    }
    ok = true;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) ok = false;
    }
    if (ok) {
        cout << "yes\n";
        cout << u1 << " " << u2 << "\n";
    } else {
        cout << "no\n";
    }
}