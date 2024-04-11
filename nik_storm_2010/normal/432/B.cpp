#include <cstdio>

using namespace std;
const int N = 200000;

int cnt[N], a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) printf("%d %d\n", n - 1 + cnt[b[i]], n - 1 - cnt[b[i]]);
    return 0;
}