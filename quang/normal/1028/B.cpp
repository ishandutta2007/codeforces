#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int num = (n - 1) / 9 + 1;
    for (int i = 1; i <= num; i++) {
        cout << 9;
    }
    for (int i = 1; i < num; i++) {
        cout << 0;
    }
    cout << 1 << endl;
    for (int i = 1; i <= num; i++) {
        cout << 9;
    }
    cout << endl;
    return 0;
}