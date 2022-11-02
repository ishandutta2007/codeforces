#include <cstdio>

using namespace std;
const int N = 500;

char a[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = 'D';
    for (int i = 1; i <= n / 2; i++) for (int j = 1; j <= n / 2 - i + 1; j++) a[i][j] = a[i][n - j + 1] = a[n - i + 1][j] = a[n - i + 1][n - j + 1] = '*';
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        printf("%c", a[i][j]);
        if (j == n) printf("\n");
    }
    return 0;
}