#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

int a1,a2,a3,a4;
int i,j;

int main()
{
    scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
    if (a3>a4+1 || a3+1<a4)
        printf("-1\n");
    else if (a4+1==a3)
    {
        if (a1<a3 || a2<a3)
            printf("-1\n");
        else
        {
            for (i=0;i<(a1-a3);i++)
                printf("4");
            for (i=0;i<a3;i++)
                printf("47");
            for (i=0;i<(a2-a3);i++)
                printf("7");
            printf("\n");
        }
    }
    else if (a4==a3+1)
    {
        if (a1 < a4 || a2<a4)
            printf("-1\n");
        else
        {
            printf("7");
            for (i=0;i<(a1-a3-1);i++)
                printf("4");
            for (i=0;i<(a3);i++)
                printf("47");
            for (i=0;i<(a2-a3-1);i++)
                printf("7");
            printf("4\n");
        }
    }
    else
    {
        if (a1==a4)
        {
            if (a2<a4+1)
                printf("-1\n");
            else
            {
                printf("7");
                for (i=0;i<a3;i++)
                    printf("47");
                for (i=0;i<(a2-a4-1);i++)
                    printf("7");
                printf("\n");
            }
        }
        else if(a1>a4)
        {
            for (i=0;i<(a1-a4-1);i++)
                printf("4");
            for (i=0;i<a3;i++)
                printf("47");
            for (i=0;i<(a2-a3);i++) 
                printf("7");
            printf("4\n");
        }
        else
            printf("-1\n");
    }
}