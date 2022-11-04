#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
const int b_size=1000;
struct Point
{
    int x,y,id;
    bool operator < (const Point &t)const
    {
        if(x/b_size==t.x/b_size)
        {
            if(x/b_size%2)
                return y<t.y;
            else return y>t.y;
        }
        else return x<t.x;
    }
}p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
        printf("%d ",p[i].id);
    return 0;
}