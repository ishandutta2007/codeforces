#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <bitset>
using namespace std;

int n,m,x,y,i,j;
int a[200000],b[200000];
vector <int> pasanga,pasangb;

int main()
{
    cin >> n >> m >> x >> y;
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (i=0;i<m;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    i=0;
    j=0;
    while (i<n && j<m)
    {
        if (b[j]>=a[i]-x && b[j]<=a[i]+y)
        {
            pasanga.push_back(i);
            pasangb.push_back(j);
            ++i;
            ++j;
        }
        else if (b[j]<a[i]-x)
            ++j;
        else
            ++i;
    }
    printf("%d\n",pasanga.size());
    for (i=0;i<pasanga.size();i++)
        printf("%d %d\n",pasanga[i]+1,pasangb[i]+1);
}