#include <iostream>

using namespace std;

int n;
int a[500];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (true) {
        bool q = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {a[i]--; cout << "P"; q = true;}
            if (i != n-1) cout << "R";
        }
        if (!q) break;
        for (int i = 0; i < n-1; i++) cout << "L";
    }
    cout << endl;
}