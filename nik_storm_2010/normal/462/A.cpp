#include <cstdio>

using namespace std;
const int N = 500;

char a[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    bool ok = false;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ok |= ((a[i - 1][j] == 'o') + (a[i + 1][j] == 'o') + (a[i][j - 1] == 'o') + (a[i][j + 1] == 'o')) % 2;
    puts((!ok) ? "YES" : "NO");
    return 0;
}