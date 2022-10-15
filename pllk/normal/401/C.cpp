#include <iostream>

using namespace std;

int n, m;
int x[1010101];

int main() {
    cin >> n >> m;
    if (n > 1 && m < n-1) {
        cout << -1 << endl;
        return 0;
    }
    int a = n+1;
    for (int i = 0; i < m; i++) {
        if (x[i%a] == 2) {
            cout << -1 << endl;
            return 0;
        }
        x[i%a]++;
    }
    if (a == 1) {
        for (int i = 0; i < x[0]; i++) cout << "1";
        cout << endl;
        return 0;
    }
    for (int i = 0; i < x[a-2]; i++) cout << "1";
    cout << "0";
    for (int i = 0; i < a-2; i++) {
        for (int j = 0; j < x[i]; j++) cout << "1";
        cout << "0";
    }
    for (int i = 0; i < x[a-1]; i++) cout << "1";
    cout << endl;
}