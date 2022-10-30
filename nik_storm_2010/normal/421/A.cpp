#include <cstdio>

using namespace std;
const int N = 200;

int ans[N];

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) ans[i] = 2;
    for (int i = 1; i <= a; i++)
    {
        int x;
        scanf("%d", &x);
        ans[x] = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}