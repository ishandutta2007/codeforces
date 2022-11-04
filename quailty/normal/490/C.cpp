#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1000005];
int pre[1000005],suf[1000005];
int main()
{
    scanf("%s",s+1);
    int a,b,n=strlen(s+1);
    scanf("%d%d",&a,&b);
    for(int i=1;i<=n;i++)
        pre[i]=(pre[i-1]*10+s[i]-'0')%a;
    for(int i=n,j=1;i>=1;i--,j=j*10%b)
        suf[i]=(suf[i+1]+j*(s[i]-'0'))%b;
    int res=0;
    for(int i=1;i<n;i++)
        if(pre[i]==0 && suf[i+1]==0 && s[i+1]!='0')
            res=i;
    if(!res)printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=1;i<=res;i++)
            printf("%c",s[i]);
        printf("\n");
        for(int i=res+1;i<=n;i++)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}