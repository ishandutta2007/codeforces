#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n&1)printf("7"),n-=3;
        while(n)printf("1"),n-=2;
        printf("\n");
    }
    return 0;
}