#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e5;

int a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) if (a[i] != b[i])
    {
        l = i;
        for (int j = 1; j <= n; j++) if (a[i] == b[j]) r = j;
        break;
    }
    int ansl = l, ansr = r;
    while (l < r) swap(a[l], a[r]), l++, r--;
    bool ok = true;
    for (int i = 1; i <= n; i++) if (a[i] != b[i]) ok = false;
    if (ok) printf("yes\n%d %d\n", ansl, ansr); else printf("no\n");
    return 0;
}