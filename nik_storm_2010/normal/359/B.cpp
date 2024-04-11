#include<cstdio>

using namespace std;

bool used[200000];
int a[200000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    n *= 2;
    if (k == 0) {
        a[1] = 1;
        a[2] = 2;
        used[1] = true;
        used[2] = true;
    }
    else {
        a[1] = n;
        a[2] = n - k;
        used[n] = true;
        used[n - k] = true;
    }
    int i = 3;
    int j = 1;
    while (i < n) {
        while (used[j]) j++;
        a[i] = j;
        j++;
        while (used[j]) j++;
        a[i + 1] = j;
        j++;
        i += 2;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}