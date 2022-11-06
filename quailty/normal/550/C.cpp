#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int main()
{
    int a[4];
    scanf("%s",s);
    int len=strlen(s);
    bool isok=0;
    int ans=0;
    for(int i=0;i<1000;i+=8)
    {
        memset(a,0,sizeof(a));
        int t=i,loc=(i==0);
        while(t>0)
        {
            a[loc++]=t%10;
            t/=10;
        }
        reverse(a,a+loc);
        int now=0;
        for(int j=0;j<len;j++)
        {
            if(s[j]-'0'==a[now])
            {
                now++;
            }
            if(now==loc)
            {
                ans=i;
                isok=1;
                break;
            }
        }
    }
    if(!isok)printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d\n",ans);
    }
    return 0;
}