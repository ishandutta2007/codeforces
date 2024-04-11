#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];
int n;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cur = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || s[i] != s[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        res = max(res, cur);
    }
    if (res < n && s[1] != s[n]) {
        int foo = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i] != s[i - 1]) {
                foo ++;
            } else {
                break;
            }
        }
        int bar = 1;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] != s[i + 1]) {
                bar++;
            } else {
                break;
            }
        }
        res = max (res, foo + bar);
    }
    cout << res << endl;
    return 0;
}