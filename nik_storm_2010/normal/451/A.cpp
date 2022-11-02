#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n > m) n = m;
    if (n % 2 == 0) puts("Malvika"); else puts("Akshat");
    return 0;
}