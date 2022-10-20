#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT

using namespace std;

int n, m;

int main()
{
    //filein, fileout;
    scanf("%d%d", &n, &m);
    int x = n / m, y = n % m;
    for(int i = 1; i <= y; i++) printf("%d ", x + 1);
    for(int i = y + 1; i <= m; i++) printf("%d ", x);
    return 0;
}