#include <bits/stdc++.h>
using namespace std;

char wcz[107];
int l;

int wyn;

int main()
{
    scanf("%s", wcz+1);
    for (int i=1; wcz[i]; i++)
    {
        l++;
        if (wcz[i]==wcz[i+1])
        continue;
        wyn+=(!(l&1));
        l=0;
    }
    printf("%d\n", wyn);
    return 0;
}