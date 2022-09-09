#include <cstdio>
#include <iostream>

using namespace std;

int n, mas[100000];

int main() {
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
        if (i == mas[i]) {
            ++ans;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == mas[mas[i]] && i != mas[i]) {
            cout << ans + 2;
            return 0;
        }
    }
    cout << min(ans + 1, n);

    return 0;
}