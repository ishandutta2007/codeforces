#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1005][1005];
int main()
{
    int n=0;
    while(gets(s[n]))n++;
    int len=0;
    for(int i=0;i<n;i++)
        len=max(len,(int)strlen(s[i]));
    for(int i=0;i<len+2;i++)printf("*");
    printf("\n");
    int now=0;
    for(int i=0;i<n;i++,printf("\n"))
    {
        printf("*");
        int t=len-strlen(s[i]);
        for(int i=0;i<(t+now)/2;i++)printf(" ");
        printf("%s",s[i]);
        for(int i=0;i<(t+1-now)/2;i++)printf(" ");
        printf("*");
        now^=t&1;
    }
    for(int i=0;i<len+2;i++)printf("*");
    return 0;
}