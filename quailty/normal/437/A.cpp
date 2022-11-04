#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int len[4],ok[4];
int main()
{
    for(int i=0;i<4;i++)
    {
        scanf("%s",s);
        len[i]=(int)strlen(s)-2;
    }
    for(int i=0;i<4;i++)
    {
        int isok=1;
        for(int j=0;j<4;j++)
        {
            if(i==j)continue;
            isok&=(2*len[i]<=len[j]);
        }
        ok[i]|=isok;
        isok=1;
        for(int j=0;j<4;j++)
        {
            if(i==j)continue;
            isok&=(len[i]>=2*len[j]);
        }
        ok[i]|=isok;
    }
    int cnt=0;
    for(int i=0;i<4;i++)
        cnt+=ok[i];
    if(cnt!=1)printf("C");
    else for(int i=0;i<4;i++)
        if(ok[i])
        {
            printf("%c",'A'+i);
            break;
        }
    return 0;
}