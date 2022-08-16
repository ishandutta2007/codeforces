# include <cstdio>

int main()
{
    int a1,a2,a3,a4;
    scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
    
    if(a1<a3||a2<a3||a1<a4||a2<a4)
    {
        printf("-1\n");
        return 0;
    }
    if(a3>a4+1||a4>a3+1)
    {
        printf("-1\n");
        return 0;
    }
    if(a3>a4)
    {
        for(int i=0;i<a1-a4;i++)printf("4");
        for(int i=0;i<a4;i++)printf("74");
        for(int i=0;i<a2-a4;i++)printf("7");
        printf("\n");
    }
    else if(a4>a3)
    {
        printf("7");
        for(int i=0;i<a1-a3;i++)printf("4");
        for(int i=1;i<a3;i++)printf("74");
        for(int i=0;i<a2-a3;i++)printf("7");
        printf("4\n");
    }
    else
    {
        if(a1==a3&&a2>a3)
        {
            for(int i=0;i<a3;i++)printf("74");
            for(int i=0;i<a2-a3;i++)printf("7");
            printf("\n");
        }
        else if(a1>a3)
        {
            for(int i=0;i<a1-a3;i++)printf("4");
            for(int i=1;i<a3;i++)printf("74");
            for(int i=0;i<a2+-a3;i++)printf("7");
            printf("74\n");
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    return 0;
}