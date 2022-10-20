#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, x, y;
char a[N];

int main() {
    int last = 1;
    scanf("%d %d %d", &n, &x, &y);
    scanf("%s", a + 1);
    int black = 0;
    int hasWhite = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - '0' == last) {
            continue;
        }
        if (a[i] - '0' == 0) {
            hasWhite = 1;
        } else {
            black++;
        }
        last = a[i] - '0';
    }
    if (!hasWhite) {
        cout << 0 << endl;
    } else {
        if (last == 1) {
            black--;
        }
        cout << 1ll * min(x, y) * black + y << endl;
    }
    return 0;
}