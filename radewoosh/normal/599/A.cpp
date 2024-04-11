#include <bits/stdc++.h>
using namespace std;

int n, m, x;

int wyn;

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    wyn=n+m+x;
    wyn=min(wyn, 2*(n+m));
    wyn=min(wyn, 2*(n+x));
    wyn=min(wyn, 2*(m+x));
    printf("%d\n", wyn);
    return 0;
}