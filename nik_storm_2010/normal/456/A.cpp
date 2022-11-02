#include <cstdio>

using namespace std;
const int N = 2e5;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x] = y;
    }
    bool ok = true;
    for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) ok = false;
    puts((ok) ? "Poor Alex" : "Happy Alex");
    return 0;
}