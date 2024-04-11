#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    if (n!=1)
    {
        if (m>(n/2))
        printf("%d", m-1);
        else
        printf("%d", m+1);
    }
    else
    {
        printf("1");
    }
    return 0;
}