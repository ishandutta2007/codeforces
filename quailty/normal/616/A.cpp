#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char c[1000005],d[1000005];
int main()
{
    scanf("%s%s",c,d);
    char *a=c,*b=d;
    while(*a=='0')a++;
    while(*b=='0')b++;
    if(strlen(a)<strlen(b))printf("<");
    else if(strlen(a)>strlen(b))printf(">");
    else
    {
        int res=strcmp(a,b);
        if(res<0)printf("<");
        else if(res==0)printf("=");
        else printf(">");
    }
    return 0;
}