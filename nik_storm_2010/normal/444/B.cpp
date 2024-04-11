#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 200000;
const int LIM = 500;

int a[N], b[N], c[N], pos[N], num[N], cnt;
ll x;

ll get_next_x()
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

int main()
{
    int n, d;
    scanf("%d %d %I64d", &n, &d, &x);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 0; i < n; i++) swap(a[i], a[get_next_x() % (i + 1)]);
    for (int i = 0; i < n; i++) b[i] = (i < d) ? 1 : 0;
    for (int i = 0; i < n; i++) swap(b[i], b[get_next_x() % (i + 1)]);
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0) continue;
        cnt++;
        num[cnt] = i;
    }
    if (n <= 1000)
    {
        for (int i = 0; i < n; i++) for (int j = 1; j <= cnt && num[j] <= i; j++) c[i] = max(c[i], a[i - num[j]]);
        for (int i = 0; i < n; i++) printf("%d\n", c[i]);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >= n - LIM; j--)
        {
            if (pos[j] > i) continue;
            if (b[i - pos[j]] == 1) { c[i] = j; break; }
        }
        if (c[i] != 0) continue;
        for (int j = 1; j <= cnt && num[j] <= i; j++) c[i] = max(c[i], a[i - num[j]]);
    }
    for (int i = 0; i < n; i++) printf("%d\n", c[i]);
    return 0;
}