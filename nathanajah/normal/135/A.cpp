#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

int arr[200000];
int i;
int n;
int nummax,maxi=0;
int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if (arr[i]>maxi)
        {
            maxi=arr[i];
            nummax=i;
        }
    }
    if (maxi==1)
        arr[nummax]=2;
    else
        arr[nummax]=1;
    sort(arr,arr+n);
    for (i=0;i<n;i++)
    {
        printf("%d",arr[i]);
        if (i==n-1)
            printf("\n");
        else
            printf(" ");
    }
    
}