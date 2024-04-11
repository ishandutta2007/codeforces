#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0, nom;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        x = (x + m - 1) / m;
        if (x >= ans) ans = x, nom = i;
    }
    printf("%d\n", nom);
    return 0;
}