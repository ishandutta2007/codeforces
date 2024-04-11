#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005],t[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    bool flag=0;
    int cnt=0;
    t[0]='1';
    while(n--)
    {
        scanf("%s",s);
        int len=strlen(s),sum=0;
        for(int i=0;i<len;i++)
            sum+=s[i]-'0';
        if(sum==0)flag=1;
        if(sum>1)strcpy(t,s);
        else cnt+=len-1;
    }
    if(flag)printf("0\n");
    else
    {
        printf("%s",t);
        for(int i=0;i<cnt;i++)
            printf("0");
        printf("\n");
    }
    return 0;
}