#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    ll operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
}p[MAXN],stk[MAXN];
bool cmp(Point a,Point b)
{
    a=a-p[0],b=b-p[0];
    return a*b ? a*b>0 : (a^a)<(b^b);
}
int Graham(int n)
{
    sort(p,p+n);
    sort(p+1,p+n,cmp);
    int top=0;
    for(int i=0;i<n;i++)
    {
        while(top>1 && (p[i]-stk[top-1])*(stk[top-1]-stk[top-2])>=0)top--;
        stk[top++]=p[i];
    }
    return top;
}
vector<int> getMax(int n)
{
    vector<int>res(3);
    ll now=0;
    for(int i=0;i<n;i++)
        for(int j=(i+1)%n,k=j;j!=i;j=(j+1)%n)
        {
            while((stk[j]-stk[i])*(stk[k]-stk[i])<=(stk[j]-stk[i])*(stk[(k+1)%n]-stk[i]))k=(k+1)%n;
            if((stk[j]-stk[i])*(stk[k]-stk[i])>now)now=(stk[j]-stk[i])*(stk[k]-stk[i]),res={i,j,k};
        }
    return res;
}
int main()
{
    int n;
    scanf("%d%*d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    vector<int>res=getMax(Graham(n));
    for(int i=0;i<3;i++)
    {
        Point t=stk[res[i]]+stk[res[(i+1)%3]]-stk[res[(i+2)%3]];
        printf("%I64d %I64d\n",t.x,t.y);
    }
    return 0;
}