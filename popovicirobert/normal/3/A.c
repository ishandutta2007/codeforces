#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,lin1,col1,lin,col,min,i;
    char a1,a2;
    a1=fgetc(stdin);
    scanf("%d" ,&n1);
    a2=fgetc(stdin);
    a2=fgetc(stdin);
    scanf("%d" ,&n2);
    a1=a1-'a';
    a2=a2-'a';
    if(n1<n2)
        lin=n2-n1+1;
    else
        lin=n1-n2+1;
    if(a1>a2)
        col=a1-a2+1;
    else
        col=a2-a1+1;
    if(lin>col)
        printf("%d\n" ,lin-1);
    else
        printf("%d\n" ,col-1);
    if(lin<col)
        min=lin-1;
    else
        min=col-1;
    lin1=n1;
    col1=a1;
    if(lin1!=n2&&col1!=a2)
    {
        if(n1>n2)
        {
            if(a1<a2)
                for(i=0; i<min; i++)
                {
                    printf("RD\n");
                    lin1--;
                    col1++;
                }
            else
                for(i=0; i<min; i++)
                {
                    printf("LD\n");
                    lin1--;
                    col1--;
                }
        }
        else
        {
            if(a1<a2)
                for(i=0; i<min; i++)
                {
                    printf("RU\n");
                    lin1++;
                    col1++;
                }
            else
                for(i=0; i<min; i++)
                {
                    printf("LU\n");
                    lin1++;
                    col1--;
                }
        }
    }
    if(lin1==n2)
    {
        while(col1<a2)
        {
            printf("R\n");
            col1++;
        }
        while(col1>a2)
        {
            printf("L\n");
            col1--;
        }
    }
    else
    {
        while(lin1<n2)
        {
            printf("U\n");
            lin1++;
        }
        while(lin1>n2)
        {
            printf("D\n");
            lin1--;
        }
    }
    return 0;
}