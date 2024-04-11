#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, l, a[2000006];
char str[1000006], nStr[2000006];

int main() {
    for (scanf("%d", &t); t--; ) {
        scanf("%s", str);
        l = strlen(str);
        int x = 0, y = l - 1;
        while (x < y && str[x] == str[y]) x++, y--;
        if (x >= y) {
            printf("%s\n", str);
            continue;
        }
        for (int j = x; j <= y; j++) nStr[j - x] = str[j];
        nStr[y - x + 1] = 0;
        l = y - x + 1;
        nStr[2 * l + 1] = 0;
        for (int i = l - 1; i >= 0; i--) nStr[2 * i + 1] = nStr[i], nStr[2 * i + 2] = '#';
        nStr[0] = '#';
        int r = -1, c = -1;
        for (int i = 0; i < 2 * l + 1; i++) {
            a[i] = r >= i ? min(r - i, a[2 * c - i]) : 0;
            while (i - a[i] - 1 >= 0 && i + a[i] + 1 < 2 * l + 1 && nStr[i - a[i] - 1] == nStr[i + a[i] + 1]) a[i]++;
            if (i + a[i] > r) r = i + a[i], c = i;
        }
        int pre = 0, suf = 0;
        for (int i = 0; i <= l; i++) {
            if (a[i] == i) pre = max(pre, a[i]);
            if (a[2 * l - i] == i) suf = max(suf, a[2 * l - i]);
        }
        for (int i = 0; i < x; i++) printf("%c", str[i]);
        if (pre >= suf) for (int i = x; i < x + pre; i++) printf("%c", str[i]);
        else for (int i = y - suf + 1; i <= y; i++) printf("%c", str[i]);
        for (int i = y + 1; str[i]; i++) printf("%c", str[i]);
        puts("");
    }
}