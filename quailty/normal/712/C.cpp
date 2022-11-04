#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int now[3]={y,y,y},res=0;
    while(1)
    {
        sort(now,now+3);
        if(now[0]==x)break;
        res++;
        now[0]=min(x,now[1]+now[2]-1);
    }
    return 0*printf("%d",res);
}