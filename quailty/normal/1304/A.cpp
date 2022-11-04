#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        printf("%d\n",(y-x)%(a+b)==0 ? (y-x)/(a+b) : -1);
    }
    return 0;
}