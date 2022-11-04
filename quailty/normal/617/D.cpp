#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
}p[5];
bool check1()
{
    if(p[0].x==p[1].x && p[1].x==p[2].x)return 1;
    if(p[0].y==p[1].y && p[1].y==p[2].y)return 1;
    return 0;
}
bool check2()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==j)continue;
            int k;
            for(k=0;k==i || k==j;k++);
            if(p[k].x==p[i].x && p[k].y>=min(p[i].y,p[j].y) && p[k].y<=max(p[i].y,p[j].y))return 1;
            if(p[k].y==p[j].y && p[k].x>=min(p[i].x,p[j].x) && p[k].x<=max(p[i].x,p[j].x))return 1;
        }
    return 0;
}
int main()
{
    for(int i=0;i<3;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    //res=1;
    if(check1())printf("1\n");
    else if(check2())printf("2\n");
    else printf("3\n");
    return 0;
}