#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int d,n;
int a[3000];
int i;
int res;
int now;

int main()
{
    scanf("%d",&d);
    scanf("%d",&n);
    for (i=0;i<n;++i)
        scanf("%d",&a[i]);
    now=0;
    for (i=0;i<n;++i)
    {
        res+=(d-now)%d;
        now=a[i];
    }
    printf("%d\n",res);
}