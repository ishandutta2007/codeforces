#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <deque>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int a,b;
    int n=0;
    scanf("%d %d",&a,&b);
    while (b>0)
    {
        n=10*n+b%10;
        b/=10;
    }
    printf("%d\n",a+n);
}