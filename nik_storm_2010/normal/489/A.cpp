#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 5e3;

int a[N];

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n - 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int nom = i;
        for (int j = i + 1; j <= n; j++) if (a[j] < a[nom]) nom = j;
        swap(a[i], a[nom]);
        printf("%d %d\n", i - 1, nom - 1);
    }
    return 0;
}