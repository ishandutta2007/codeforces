#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, k;

int main ()
{
    scanf("%d%d", &n, &k);
    k -= 2 * n;
    printf("%d", max(n - k, 0));
    return 0;
}