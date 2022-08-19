#include <bits/stdc++.h>
using namespace std;

int n;

vector <int> wyn;

int ile;

int ilema(int v)
{
    int ret=0;
    while(!(v%5))
    {
        v/=5;
        ret++;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n*20; i++)
    {
        ile+=ilema(i);
        if (ile>n)
        break;
        if (ile==n)
        wyn.push_back(i);
    }
    printf("%d\n", (int)wyn.size());
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i]);
    }
    printf("\n");
    return 0;
}