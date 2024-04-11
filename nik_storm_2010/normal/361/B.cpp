#include<cstdio>

using namespace std;

int a[200000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == k) { printf("-1"); return 0; }
    int l = k;
    for (int i = 2; i <= n; i++)
    if (l != 0) {
        l--;
        a[i] = i;
    }
    else {
        if (i == n) a[i] = 1; else a[i] = i + 1;
    }
    if (k == n - 1) a[1] = 1; else a[1] = k + 2;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}