#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    char s[15];
    scanf("%s",s);
    scanf("%s",s);
    if(*s=='m')
    {
        if(x<=29)printf("12\n");
        else if(x<=30)printf("11\n");
        else printf("7\n");
    }
    else
    {
        if(x==5 || x==6)printf("53\n");
        else printf("52\n");
    }
    return 0;
}