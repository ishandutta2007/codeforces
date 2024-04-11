#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m[1010101];
int t[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        m[t[i]] = 1;
    }
    t[n] = -1;
    sort(t, t+n+1);
    int p = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (!m[i]) continue;
        for (int j = i; j <= 1000000; j += i) {
            auto x = lower_bound(t, t+n+1, j+i);
            x--;
            if (*x-j > p) p = *x-j;
        }
    }
    cout << p << "\n";
}