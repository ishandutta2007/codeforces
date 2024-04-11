#include <cstdio>

using namespace std;
const int N = 200000;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cnt = 0, nom = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i + 1;
        if (j > n) j -= n;
        if (a[i] > a[j]) cnt++, nom = j;
    }
    if (cnt == 0)
    {
        puts("0");
        return 0;
    }
    if (cnt == 1)
    {
        if (nom == 1) printf("0\n"); else printf("%d\n", n - nom + 1);
    }
    else puts("-1");
    return 0;
}