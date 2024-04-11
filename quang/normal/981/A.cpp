#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
char a[N];

bool check(int l , int r) {
    for (int i = 0; i <= r - l; i++) {
        if (a[l + i] != a[r - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%s", a + 1);
    int res= 0;
    n = strlen(a + 1);
    // check(1, n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (!check(i, j)) {
                res = max(res, j - i + 1);
            }
        }
    }
    cout << res << endl;
    return 0;
}