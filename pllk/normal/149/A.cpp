#include <iostream>
#include <algorithm>

using namespace std;

int k;
int a[12];

int main() {
    cin >> k;
    for (int i = 0; i < 12; i++) cin >> a[i];
    sort(&a[0], &a[12]);
    int t = 0, m = 0;
    for (int i = 11; i >= 0; i--) {
        if (m >= k) break;
        m += a[i];
        t++;
    }
    if (m < k) t = -1;
    cout << t << endl;
}