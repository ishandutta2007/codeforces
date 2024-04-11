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

int n,i;
int tot;
int main()
{
    scanf("%d",&n);
    tot=1;
    for (i=1;i<=n-1;++i)
    {
        tot+=(12*i);
    }
    printf("%d\n",tot);
}