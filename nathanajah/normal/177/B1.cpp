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

int n;
int hitung(int x)
{
    if (x==1)
        return 1;
    int i;
    for (i=2;i*i<=x;++i)
    {
        if (x%i==0)
            break;
    }
    if (x%i!=0)
        i=x;
    return x+hitung(x/i);
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",hitung(n));
}