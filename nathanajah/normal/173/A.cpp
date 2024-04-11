#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <deque>
using namespace std;

int n,m,k;
string s1,s2;
int i;
int arr[2000000];
int x[2000000];
int y[2000000];
int xx,yy;

bool cmp(char a, char b)
{
    if (a=='R' && b=='S')
        return true;
    if (a=='S' && b=='P')
        return true;
    if (a=='P' && b=='R')
        return true;
    return false;
}


int main()
{
    scanf("%d",&n);
    cin >> s1;
    cin >> s2;
    m=s1.length();
    k=s2.length();
    for (i=1;i<=m*k;++i)
    {
        x[i]=x[i-1];
        y[i]=y[i-1];
        if (cmp(s1[(i-1)%m],s2[(i-1)%k]))
        {
            ++x[i];
        }
        else if (cmp(s2[(i-1)%k],s1[(i-1)%m]))
        {
            ++y[i];
        }
    }
    xx=(n/(m*k))*x[m*k];
    yy=(n/(m*k))*y[m*k];
    xx+=x[n%(m*k)];
    yy+=y[n%(m*k)];
    printf("%d %d\n",yy,xx);
}