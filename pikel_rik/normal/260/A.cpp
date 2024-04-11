#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    int flag = 0;

    for (int i = 0; i < 10; i++) {
        if ((10 * a + i) % b == 0) {
            a = 10 * a + i;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "-1";
    else {
        cout << a;
        for (int i = 1; i < n; i++) {
            cout << 0;
        }
    }

    return 0;
}