#include <cstdio>

using namespace std;
const int N = 200000 + 10;

bool used[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        used[x] = true;
    }
    for (int i = 1; i <= n; i++) if (!used[i]) printf("%d\n", i);
    return 0;
}