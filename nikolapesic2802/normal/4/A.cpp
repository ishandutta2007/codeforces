#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    scanf("%i",&w);
    if(w%2==0&&w>2)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}