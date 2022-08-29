#include <cstdio>
using namespace std;

const int MOD = 1000000007;

int N;

int main()
{
    scanf("%d", &N);
    int red = 0, blue = 0;

    for (int i = 0; i < N; i++)
        if (i % 2 == 0)
        {
            red += blue + 1;
            red %= MOD;
        }
        else
        {
            blue += red + 1;
            blue %= MOD;
        }

    printf("%d\n", (red + blue) % MOD);
    return 0;
}