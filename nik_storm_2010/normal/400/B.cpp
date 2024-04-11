#include<cstdio>
#include<string>

using namespace std;
const int N = 1000 + 10;

char a[N][N];
bool used[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", &a[i]);
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < m; j++) if (a[i][j] != '*') s += a[i][j];
        if (s == "SG")
        {
            printf("-1");
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'G') n1 = j;
            if (a[i][j] == 'S') n2 = j;
        }
        if (!used[n2 - n1]) ans++;
        used[n2 - n1] = true;
    }
    printf("%d\n", ans);
    return 0;
}