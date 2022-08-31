#include <bits/stdc++.h>
using namespace std;

int n, m;

int s;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; 1; i++)
    {
        if (!(i%6))
        {
            s++;
        }
        else
        {
            if (!(i%2) && n)
            {
                n--;
            }
            if (!(i%3) && m)
            {
                m--;
            }
        }
        if (s>=n+m)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}