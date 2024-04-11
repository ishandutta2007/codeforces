#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,x,y;
        scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
        printf("%s\n",max(0,x-a)+max(0,y-b)<=c ? "YES" : "NO");
    }
    return 0;
}