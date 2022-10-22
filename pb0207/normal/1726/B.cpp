#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(m<n)
        {
            puts("No");
            continue;
        }
        if(n==1)
        {
            puts("Yes");
            printf("%d\n",m);
            continue;
        }
        if(m%2==1)
        {
            if(n%2==0)
            {
                puts("No");
            }
            else
            {
                puts("Yes");
                for(int i=1;i<=n-1;i++)
                    printf("%d ",1);
                int x=(m-(n-1));
                for(int i=1;i<=1;i++)
                    printf("%d%c",x," \n"[i==1]);

            }
            continue;
        }
        if(n%2==0)
        {
            puts("Yes");
            for(int i=1;i<=n-2;i++)
                printf("%d ",1);
            int x=(m-(n-2))/2;
            for(int i=1;i<=2;i++)
                printf("%d%c",x," \n"[i==2]);
        }
        else
        {
            puts("Yes");
            for(int i=1;i<=n-1;i++)
                printf("%d ",1);
            int x=(m-(n-1));
            for(int i=1;i<=1;i++)
                printf("%d%c",x," \n"[i==1]);

        }
    }
}