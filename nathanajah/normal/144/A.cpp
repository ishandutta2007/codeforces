#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int n,i;
int posimax,posimin;
int maxi=-1,mini=2000000000;
int banyak;
int temp;

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if (temp>maxi)
        {
            posimax=i;
            maxi=temp;
        }
        if (temp<=mini)
        {
            posimin=i;
            mini=temp;
        }
    }
    if (n==1)
        printf("0\n");
    else
    {
        if (posimax<posimin)
            printf("%d\n",posimax+(n-posimin-1));
        else
            printf("%d\n",posimax+(n-posimin-2));
            
    }
}