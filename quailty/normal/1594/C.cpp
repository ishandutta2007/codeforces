#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        static char s[300005],c[5];
        scanf("%d%s%s",&n,c,s+1);
        bool isok=1;
        for(int i=1;i<=n;i++)
            isok&=(s[i]==c[0]);
        if(isok)
        {
            printf("0\n");
            continue;
        }
        for(int i=2;i<=n && !isok;i++)
        {
            bool flag=1;
            for(int j=i;j<=n;j+=i)
                flag&=(s[j]==c[0]);
            if(flag)
            {
                printf("1\n%d\n",i);
                isok=1;
            }
        }
        if(!isok)printf("2\n%d %d\n",n-1,n);
    }
    return 0;
}