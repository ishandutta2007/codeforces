#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[105];
char buf[105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        cnt[strlen(buf)]++;
    }
    int tar;
    scanf("%s",buf);
    tar=strlen(buf);
    int res=0,now=0;
    for(int i=1;i<tar;i++)
        for(int j=0;j<cnt[i];j++)
        {
            res++;
            now++;
            if(now==k)
            {
                res+=5;
                now=0;
            }
        }
    printf("%d ",res+1);
    for(int j=0;j<cnt[tar];j++)
    {
        if(now==k)
        {
            res+=5;
            now=0;
        }
        res++,now++;
    }
    printf("%d\n",res);
    return 0;
}