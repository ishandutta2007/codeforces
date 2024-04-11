#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const db eps=1e-18;
struct Point
{
    db x,y;
    vector<int> ids;
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator - (const Point& t) const {
        return Point(x-t.x,y-t.y);
    }
    db operator * (const Point& t) const {
        return x*t.y-y*t.x;
    }
    bool operator < (const Point& t) const {
        return x==t.x ? y<t.y : x<t.x;
    }
    bool operator == (const Point& t) const {
        return x==t.x && y==t.y;
    }
};
int main()
{
    int n;
    scanf("%d",&n);
    vector<Point> vec;
    for(int i=0;i<n;i++)
    {
        int s,r;
        scanf("%d%d",&s,&r);
        vec.push_back(Point(1.0/s,1.0/r));
        vec.back().ids.push_back(i);
    }
    sort(vec.begin(),vec.end());
    vector<Point> stk;
    int top=0;
    for(auto& p : vec)
    {
        if(top>0 && p==stk[top-1])
        {
            stk[top-1].ids.push_back(p.ids[0]);
            continue;
        }
        while(top>1 && (p-stk[top-1])*(stk[top-1]-stk[top-2])>eps)
            stk.pop_back(),--top;
        stk.push_back(p),++top;
    }
    vector<int> isok(n);
    for(size_t i=0;i<stk.size();i++)
    {
        if(i>0 && stk[i].y>=stk[i-1].y)break;
        for(auto id : stk[i].ids)isok[id]=1;
    }
    for(int i=0,f=1;i<n;i++)
        if(isok[i])printf("%s%d",(f ? "" : " "),i+1),f=0;
    return 0;
}