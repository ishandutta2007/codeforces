#include <cstdio>

using namespace std;

int main()
{
    int n, m, it;
    scanf("%d %d", &n, &m);
    int k = m;
    for (it = 0; n >= 1; it++, n--)
    {
        k--;
        if (k == 0) n++, k = m;
    }
    printf("%d\n", it);
    return 0;
}