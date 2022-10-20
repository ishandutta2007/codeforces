#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 550

using namespace std;

int n, m;
double kq = 0.0;
int x[LIMIT];

int main()
{
    //filein, fileout;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", x + i);
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        kq = max(kq, 1.0 * (x[a] + x[b]) / c);
    }
    printf("%0.9f", kq);
    return 0;
}