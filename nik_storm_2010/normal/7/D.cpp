#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
const int N = 1e7 + 10;

char a[N];
int z[N], pal[N];

int main() {
    scanf("%s", &a);
    int d = strlen(a);
    a[d] = '$';
    for (int i = 0; i < d; i++) a[d + i + 1] = a[d - i - 1];
    int nd = 2 * d + 1;
    int l = 0, r = 0;
    for (int i = 1; i < nd; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < nd && a[i + z[i]] == a[z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    pal[0] = 1;
    long long sum = 1;
    for (int i = 1; i < d; i++) {
        int l = (i + 1) >> 1;
        if (z[nd - i - 1] >= l) pal[i] = pal[l - 1] + 1;
        sum += pal[i];
    }
    printf("%I64d\n", sum);
    return 0;
}