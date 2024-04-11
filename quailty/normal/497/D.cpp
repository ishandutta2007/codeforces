#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef double db;
const int MAXN=1005;
const db eps=1e-9;
int sgn(db x)
{
    if(x>eps)return 1;
    if(x<-eps)return -1;
    return 0;
}
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    db operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    db operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
}P,Q;
vector<Point>A,B;
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e):s(_s),e(_e){}
};
db disPTP(Point a,Point b)
{
    return sqrt((a-b)^(a-b));
}
db disMin(Point P,Line L)
{
    db t=((P-L.s)^(L.e-L.s))/((L.e-L.s)^(L.e-L.s));
    if(t>=0 && t<=1)
    {
        Point res=L.s+(L.e-L.s)*t;
        return disPTP(P,res);
    }
    else return min(disPTP(P,L.s),disPTP(P,L.e));
}
db disMax(Point P,Line L)
{
    return max(disPTP(P,L.s),disPTP(P,L.e));
}
void input()
{
    P.input();
    int n;
    scanf("%d",&n);
    A.resize(n);
    for(int i=0;i<n;i++)
        A[i].input();
    Q.input();
    int m;
    scanf("%d",&m);
    B.resize(m);
    for(int i=0;i<m;i++)
        B[i].input();
}
int main()
{
    input();
    db r=disPTP(P,Q);
    bool isok=0;
    for(int _=0;_<2;_++)
    {
        int n=(int)A.size(),m=(int)B.size();
        for(int i=0;i<n;i++)
        {
            Point O=Q+A[i]-P;
            for(int j=0;j<m;j++)
            {
                db mi=disMin(O,Line(B[j],B[(j+1)%m]));
                db mx=disMax(O,Line(B[j],B[(j+1)%m]));
                if(sgn(mi-r)*sgn(mx-r)<=0)isok=1;
            }
        }
        swap(P,Q),swap(A,B);
    }
    return 0*printf("%s",(isok ? "YES" : "NO"));
}