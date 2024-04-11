#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
char a[N];
int cnt[100];

int main() {
    scanf("%d", &n);
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    scanf("%s", a + 1);
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        int u = a[i] - 'a';
        if (cnt[u]) {
            f = 1;
            break;
        }
        cnt[u]++;
    }
    puts(f ? "Yes" : "No");
    return 0;
}