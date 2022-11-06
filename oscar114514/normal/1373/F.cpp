#include <bits/stdc++.h>
#define N 1111111
using namespace std;

int a[N], b[N], c[N];

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i ++)
            scanf("%d", &b[i]);

        int l, m, r;
        for(l = -1, r = b[n - 1] + 1; l + 1 < r; )
        {
            m = (l + r) / 2;
            copy(a, a + n, c);
            c[0] -= m;
            c[n - 1] -= b[n - 1] - m;

            int flag = 0;
            for(int i = 0; i < n - 1; i ++)
            {
                if(c[i] <= 0)
                    c[i + 1] -= b[i];
                else if(b[i] >= c[i])
                {
                    c[i + 1] -= b[i] - c[i];
                    c[i] = 0;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }

            if(flag)
                l = m;
            else
            {
                if(c[n - 1] <= 0)
                {
                    puts("YES");
                    goto okay;
                }
                else
                    r = m;
            }
        }
        puts("NO");
        okay:;
    }
    return 0;
}