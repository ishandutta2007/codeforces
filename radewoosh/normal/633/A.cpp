#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int tak[1000007];

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    tak[0]=1;
    for (int i=0; i<=c; i++)
    {
        if (tak[i])
        {
            tak[i+a]=1;
            tak[i+b]=1;
        }
    }
    if (tak[c])
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}