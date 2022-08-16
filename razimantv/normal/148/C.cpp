# include <cstdio>

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    
    if(n<=a+b)
    {
        printf("-1\n");
    }
    else if(b==0)
    {
        if(a==0)
        {
            for(int i=0;i<n;i++)
                printf("1 ");
            printf("\n");
        }
        else if(n<a+2)
        {
            printf("-1\n");
        }
        else
        {
            printf("1 1");
            for(int i=0;i<a;i++)
                printf(" %d",i+2);
            for(int i=a+2;i<n;i++)
                printf(" 1");
            printf("\n");
        }
    }
    else
    {
        for(int i=0;i<=b;i++)
            printf("%d ",1<<i);
        for(int i=1;i<=a;i++)
            printf("%d ",(1<<b)+i);
        for(int i=a+b+1;i<n;i++)
            printf("1 ");
        printf("\n");
    }
    return 0;
}