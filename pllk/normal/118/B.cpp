#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < 2*n+1; i++) {
        int t = 0;
        for (int j = 0; j < 2*n+1; j++) {
            int m = abs(i-n)+abs(j-n);
            if (m > n && t) break;
            if (j > 0) cout << " ";
            if (m > n) cout << " ";
            if (m <= n) {
                cout << n-m;
                t = 1;
            }
        }
        cout << endl;
    }
}