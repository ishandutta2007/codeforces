#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
char s[MAXN],t[MAXN];
int main()
{
    int n,m;
    scanf("%d%d%s%s",&n,&m,s+1,t+1);
    int loc=0,res=n+1;
    for(int i=0;i+n<=m;i++)
    {
        int now=0;
        for(int j=1;j<=n;j++)
            now+=(s[j]!=t[i+j]);
        if(res>now)res=now,loc=i;
    }
    printf("%d\n",res);
    for(int j=1;j<=n;j++)
        if(s[j]!=t[loc+j])
            printf("%d ",j);
    return 0;
}