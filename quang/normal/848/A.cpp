#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int a[N];

int main() {
    a[0] = 0;
    for (int i = 1; i < N; i++) {
        a[i] = i * (i + 1) / 2;
    }
    int k;
    scanf("%d", &k);
    if (k == 0) {
        cout << "a" << endl;
        return 0;
    }
    for (int i = 0; i < 26 && k > 0; i++) {
        int cnt = upper_bound(a, a + N, k) - a;
        k -= a[cnt - 1];
        for (int j = 1; j <= cnt; j++) {
            putchar(i + 'a');
        }
    }
    return 0;
}