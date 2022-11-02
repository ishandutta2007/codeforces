#include <cstdio>

using namespace std;

int main()
{
    int a1, a2, a3, b1, b2, b3, n;
    scanf("%d %d %d", &a1, &a2, &a3);
    scanf("%d %d %d", &b1, &b2, &b3);
    scanf("%d", &n);
    puts(((a1 + a2 + a3 + 4) / 5 + (b1 + b2 + b3 + 9) / 10 <= n) ? "YES" : "NO");
    return 0;
}