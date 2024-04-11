#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <deque>
using namespace std;

int a,b,c;
int t;

int main()
{
    scanf("%d %d %d",&a,&b,&c);
    t=(a*c)/b;
    if ((a*c)%b!=0)
        ++t;
    t=t-c;
    t=max(t,0);
    printf("%d\n",t);
}