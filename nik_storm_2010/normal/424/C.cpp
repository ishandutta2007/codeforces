#include <cstdio>

using namespace std;
const int N = 2000000;

int cnt[N];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        ans ^= x;
    }
    for (int i = 1; i <= n; i++) cnt[i - 1] += n / i, cnt[n % i]++;
    int all = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        all = (all + cnt[i]) % 2;
        ans ^= all * i;
    }
    printf("%d\n", ans);
    return 0;
}