#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


struct queen
{
    int x;
    int y;
    int attack;
};
int n,m;
queen a[200000];
int i,j;
int cnt[100];

bool cmp1(queen a,queen b)
{
    if (a.x<b.x)
        return true;
    else if (a.x>b.x)
        return false;
    else
        return a.y<b.y;
}

bool cmp2(queen a, queen b)
{
    if (a.y<b.y)
        return true;
    else if (a.y>b.y)
        return false;
    else
        return a.x<b.x;
}

bool cmp3(queen a, queen b)
{
    if (a.x+a.y<b.x+b.y)
        return true;
    else if (a.x+a.y>b.x+b.y)
        return false;
    else
        return (a.x<b.x);
}

bool cmp4( queen a, queen b)
{
    if (a.x-a.y<b.x-b.y)
        return true;
    else if (a.x-a.y>b.x-b.y)
        return false;
    else
        return (a.x<b.x);
}
int main()
{
    scanf("%d %d",&n,&m);
    for (i=0;i<m;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort (a,a+m,cmp1);
    for (i=0;i<m;i++)
    {
        if (i>0)
            if (a[i].x==a[i-1].x)
                a[i].attack++;
        if (i<m-1)
            if (a[i].x==a[i+1].x)
                a[i].attack++;
    }
    sort(a,a+m,cmp2);
    for (i=0;i<m;i++)
    {
        if (i>0)
            if (a[i].y==a[i-1].y)
                a[i].attack++;
        if (i<m-1)
            if (a[i].y==a[i+1].y)
                a[i].attack++;
    }
    sort(a,a+m,cmp3);
    for (i=0;i<m;i++)
    {
        if (i>0)
            if (a[i].x+a[i].y==a[i-1].x+a[i-1].y)
                a[i].attack++;
        if (i<m-1)
            if (a[i].x+a[i].y==a[i+1].x+a[i+1].y)
                a[i].attack++;
    }
    sort(a,a+m,cmp4);
    for (i=0;i<m;i++)
    {
        if (i>0)
            if (a[i].x-a[i].y==a[i-1].x-a[i-1].y)
                a[i].attack++;
        if (i<m-1)
            if (a[i].x-a[i].y==a[i+1].x-a[i+1].y)
                a[i].attack++;
    }
    for (i=0;i<m;i++)
        cnt[a[i].attack]++;
    for (i=0;i<9;i++)
    {
        if (i>0)
            printf(" ");
        printf("%d",cnt[i]);
    }
    printf("\n");
        
}