#include <cstdio>

using namespace std;
const int N = 100 + 10;

int k[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &k[i]);
    int ans = 2e9;
    for (int i = 0; i < n; i++)
    {
        int sum = k[i] * 15;
        for (int j = 0; j < k[i]; j++)
        {
            int x;
            scanf("%d", &x);
            sum += x * 5;
        }
        if (ans > sum) ans = sum;
    }
    printf("%d\n", ans);
    return 0;
}