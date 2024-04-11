#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[5],t[5];
    scanf("%s%s",s,t);
    s[0]-=t[0],s[1]-=t[1];
    printf("%d\n",max(abs((int)s[0]),abs((int)s[1])));
    while(s[0] || s[1])
    {
        if(s[0]>0)s[0]--,printf("L");
        if(s[0]<0)s[0]++,printf("R");
        if(s[1]>0)s[1]--,printf("D");
        if(s[1]<0)s[1]++,printf("U");
        printf("\n");
    }
    return 0;
}