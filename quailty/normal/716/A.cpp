#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,c,la=0,res=0;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        int now;
        scanf("%d",&now);
        if(now>la+c)res=0;
        res++,la=now;
    }
    return 0*printf("%d",res);
}