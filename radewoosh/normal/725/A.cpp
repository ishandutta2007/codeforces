#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[1000007];

int tak[1000007];

int wyn;

int main()
{
    scanf("%d%s", &n, wcz+1);
    tak[0]=tak[n+1]=1;
    for (int i=1; i<=n; i++)
        if (tak[i-1] && wcz[i]=='<')
            tak[i]=1;
    for (int i=n; i; i--)
        if (tak[i+1] && wcz[i]=='>')
            tak[i]=1;
    for (int i=1; i<=n; i++)
        wyn+=tak[i];
    printf("%d\n", wyn);
    return 0;
}