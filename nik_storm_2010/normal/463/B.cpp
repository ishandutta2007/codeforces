#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 0, last = 0, energy = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        energy += last - x;
        last = x;
        if (energy < 0) ans -= energy, energy = 0;
    }
    printf("%I64d\n", ans);
    return 0;
}