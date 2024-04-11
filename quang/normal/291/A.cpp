#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY 1000000010
#define LIMIT 1010

using namespace std;

int n, c, sl, kq;
int a[LIMIT];

int main()
{
    //filein, fileout;
    scanf("%d", &n);
    int x;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if(x) a[++c] = x;
    }
    sort(a + 1, a + c + 1);
    a[c + 1] = EXTREMELY;
    for(int i = 1; i <= c + 1; i++)
    {
        if(a[i] != a[i - 1])
        {
            if(sl == 2) kq++;
            sl = 1;
        }
        else sl++;
        if(sl > 2)
        {
            printf("%d", -1);
            exit(0);
        }
    }
    printf("%d", kq);
    return 0;
}