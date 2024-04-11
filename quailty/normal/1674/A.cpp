#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(y%x==0)printf("1 %d\n",y/x);
    else printf("0 0\n");
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}