#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY 2000
#define LIMIT

using namespace std;

int n, x, a, b, c = EXTREMELY;

int main()
{
    //filein, fileout;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n - 1; i++)
    {
        scanf("%d", &x);
        a += abs(x);
        if(x < 0) b++;
        c = min(c, abs(x));
    }

    printf("%d\n", ((n % 2) || (b % 2 == 0))? a : a - 2 * c);
    return 0;
}