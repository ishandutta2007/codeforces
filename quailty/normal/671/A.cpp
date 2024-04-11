#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
struct Point
{
    db x,y;
    Point(db _x=0,db _y=0):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    db len()
    {
        return sqrt(x*x+y*y);
    }
}p[100010];
int main()
{
    for(int i=0;i<3;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    int n;
    scanf("%d",&n);
    for(int i=3;i<n+3;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    db tmp=0;
    for(int i=3;i<n+3;i++)
        tmp+=2*(p[i]-p[2]).len();
    db res=1e100;
    for(int _=0;_<2;_++)
    {
        int loc[2]={-1,-1};
        for(int i=3;i<n+3;i++)
        {
            if(loc[0]==-1)loc[0]=i;
            else if((p[i]-p[0]).len()-(p[i]-p[2]).len()<(p[loc[0]]-p[0]).len()-(p[loc[0]]-p[2]).len())
            {
                loc[1]=loc[0];
                loc[0]=i;
            }
            else if(loc[1]==-1)loc[1]=i;
            else if((p[i]-p[0]).len()-(p[i]-p[2]).len()<(p[loc[1]]-p[0]).len()-(p[loc[1]]-p[2]).len())
                loc[1]=i;
        }
        for(int i=3;i<n+3;i++)
        {
            int pt=(i==loc[0]);
            if(loc[pt]>0)res=min(res,tmp+(p[loc[pt]]-p[0]).len()-(p[loc[pt]]-p[2]).len()+min(0.0,(p[i]-p[1]).len()-(p[i]-p[2]).len()));
            else res=min(res,tmp+(p[i]-p[1]).len()-(p[i]-p[2]).len());
        }
        swap(p[0],p[1]);
    }
    printf("%.12f\n",res);
    return 0;
}