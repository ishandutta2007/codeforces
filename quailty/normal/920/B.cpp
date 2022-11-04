#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int now=1;
        for(int i=1;i<=n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(now>r)printf("0");
            else
            {
                now=max(now,l);
                printf("%d",now++);
            }
            printf("%c"," \n"[i==n]);
        }
    }
    return 0;
}