#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n,i,j;
int tmp;
int sum;

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;++i)
        for (j=0;j<n;++j)
        {
            scanf("%d",&tmp);
            if (i==j || i+j==n-1 || i==(n/2) || j==(n/2))
                sum+=tmp;
        }
    printf("%d\n",sum);
}