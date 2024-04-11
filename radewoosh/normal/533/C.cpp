#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    if (x+y<n+m)
    {
        printf("Vasiliy");
        return 0;
    }
    if (n+m<=max(x, y))
    {
        printf("Polycarp");
        return 0;
    }
    if (n<=x && m<=y)
    {
        printf("Polycarp");
        return 0;
    }
    printf("Vasiliy");
    return 0;
}