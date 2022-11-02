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
#include <deque>
#include <set>
#include <map>
using namespace std;

int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    if (n==0 && m>0)
        printf("Impossible\n");
    else
    {
        printf("%d %d\n",max(n,m),n+max(m-1,0));
    }
}