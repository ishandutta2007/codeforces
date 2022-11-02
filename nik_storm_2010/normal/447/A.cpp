#include <cstdio>

using namespace std;
const int N = 1000;

bool used[N];

int main()
{
    int n, p;
    scanf("%d %d", &p, &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        x %= p;
        if (used[x])
        {
            printf("%d\n", i);
            return 0;
        }
        used[x] = true;
    }
    puts("-1");
    return 0;
}