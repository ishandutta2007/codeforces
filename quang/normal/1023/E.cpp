#include <bits/stdc++.h>

using namespace std;

char s[10];

int n;
bool ask(int x, int y, int xx, int yy) {
    if (!(1 <= x && x <= xx && xx <= n)) {
        return 0;
    }
    if (!(1 <= y && y <= yy && yy <= n)) {
        return 0;
    }
    if ((xx - x) + (yy - y) < n - 1) {
        exit(1);
    }
    printf("? %d %d %d %d\n", x, y, xx, yy);
    fflush(stdout);
    memset(s, 0, sizeof s);
    scanf("%s", s + 1);
    return s[1] == 'Y';
}

const int N = 10010;

char res[N];
pair<int, int> a[N];

void answer() {
    printf("! ");
    printf("%s\n", res + 1);
}

int main() {
    scanf("%d", &n);
    a[1] = make_pair(1, 1);
    for (int i = 2; i <= n; i++) {
        int x = a[i - 1].first + 1;
        int y = a[i - 1].second;
        bool can = ask(x, y, n, n);
        if (can) {
            a[i] = make_pair(x, y);
        } else {
            a[i] = make_pair(a[i - 1].first, a[i - 1].second + 1);
        }
    }
    a[n * 2 - 1] = make_pair(n, n);
    for (int i = n * 2 - 2; i > n; i--) {
        int x = a[i + 1].first;
        int y = a[i + 1].second - 1;
        bool can = ask(1, 1, x, y);
        if (can) {
            a[i] = make_pair(x, y);
        } else {
            a[i] = make_pair(a[i + 1].first - 1, a[i + 1].second);
        }
    }
    for (int i = 1; i < n * 2 - 1; i++ ) {
        if (a[i].first == a[i + 1].first) {
            res[i] = 'R';
        } else {
            res[i] = 'D';
        }
    }
    answer();
    return 0;
}