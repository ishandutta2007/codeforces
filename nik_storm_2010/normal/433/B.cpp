#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 200000;

int a[N], b[N];
long long suma[N], sumb[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + a[i], sumb[i] = sumb[i - 1] + b[i];
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) printf("%I64d\n", suma[r] - suma[l - 1]); else printf("%I64d\n", sumb[r] - sumb[l - 1]);
    }
    return 0;
}