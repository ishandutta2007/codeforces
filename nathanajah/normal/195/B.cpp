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


struct basket
{
    int ind,bol;
};
int n,m;
int i,j;
basket tmp,tmp2;

bool operator<(basket a, basket b)
{
    if (a.bol>b.bol)
        return true;
    if (a.bol<b.bol)
        return false;
    if (abs(m+1-2*a.ind)>abs(m+1-2*b.ind))
        return true;
    if (abs(m+1-2*a.ind)<abs(m+1-2*b.ind))
        return false;
    return a.ind>b.ind;
}
priority_queue <basket> pq;

int main()
{
    scanf("%d %d",&n,&m);
    for (i=1;i<=m;++i)
    {
        tmp.ind=i;
        tmp.bol=0;
        pq.push(tmp);
    }
    for (i=0;i<n;++i)
    {
        tmp=pq.top();
        pq.pop();
        printf("%d\n",tmp.ind);
        tmp.bol=tmp.bol+1;
        pq.push(tmp);
    }
}