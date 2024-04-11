#include <iostream>

using namespace std;

int n;
int t[20000];

int main() {
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        m += t[i];
    }
    for (int i = 3; i <= n; i++) {
        if (n%i != 0) continue;
        for (int j = 0; j < n/i; j++) {
            int s = 0;
            for (int k = j; k < n; k += n/i) {
                s += t[k];
            }
            if (s > m) m = s;
        }
    }
    cout << m << endl;
}