#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<cstdint>

using namespace std;

typedef long long ll;
typedef long double ldb;

struct Frac
{
    ll u,d;
    Frac():u(0),d(1){}
    Frac(ll _x):u(_x),d(1){}
    Frac(ll _u,ll _d):u(_u),d(_d)
    {
        ll g=__gcd(u,d);
        u/=g,d/=g;
        if(d<0)u=-u,d=-d;
    }
    Frac operator + (const Frac &t)const
    {
        return Frac(u*t.d+d*t.u,d*t.d);
    }
    Frac operator - (const Frac &t)const
    {
        return Frac(u*t.d-d*t.u,d*t.d);
    }
    Frac operator * (const Frac &t)const
    {
        return Frac(u*t.u,d*t.d);
    }
    Frac operator / (const Frac &t)const
    {
        return Frac(u*t.d,d*t.u);
    }
    bool operator < (const Frac &t)const
    {
        return 1.0L*u*t.d<1.0L*d*t.u;
    }
    bool operator == (const Frac &t)const
    {
        return 1.0L*u*t.d==1.0L*d*t.u;
    }
    bool operator > (const Frac &t)const
    {
        return !(*this<t) && !(*this==t);
    }
    bool operator <= (const Frac &t)const
    {
        return (*this<t) || (*this==t);
    }
    bool operator >= (const Frac &t)const
    {
        return !(*this<t);
    }
};

struct Point
{
    Frac x,y;
    Point(){}
    Point(Frac _x,Frac _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const Frac &t)const
    {
        return Point(x*t,y*t);
    }
    Point operator / (const Frac &t)const
    {
        return Point(x/t,y/t);
    }
    Frac operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    Frac operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
};

struct ConvexHull
{
    struct ClassCmp
    {
        bool operator () (const Point &lhs,const Point &rhs)const
        {
            return lhs.x<rhs.x;
        }
    };
    set<Point,ClassCmp> pts;
    void init()
    {
        pts.clear();
    }
    Frac getY(const Frac &x)const
    {
        if(pts.empty())return Frac(1,0);
        Frac l=pts.begin()->x,r=(--pts.end())->x;
        if(x<l || x>r)return Frac(1,0);
        auto itr=pts.lower_bound(Point(x,0));
        if(itr==pts.begin())return pts.begin()->y;
        auto nxt=itr--;
        return itr->y+(x-itr->x)/(nxt->x-itr->x)*(nxt->y-itr->y);
    }
    void addPoint(const Point &t)
    {
        if(t.y>=getY(t.x))return;
        if(pts.find(t)!=pts.end())pts.erase(t);
        if(!pts.empty())
        {
            auto nxt=pts.lower_bound(t),pre=nxt;
            if(pre!=pts.begin())pre--;
            for(auto itr=pre;itr!=pts.begin();)
            {
                auto tmp=itr--;
                if((*tmp-t)*(*itr-*tmp)>=0)pts.erase(tmp);
            }
            for(auto itr=nxt;itr!=pts.end();)
            {
                auto tmp=itr++;
                if(itr==pts.end())break;
                if((*tmp-t)*(*itr-*tmp)<=0)pts.erase(tmp);
            }
        }
        pts.insert(t);
    }
}ch;

int main()
{
    int q,last=0;
    ll m;
    scanf("%d%lld",&q,&m);
    ch.init();
    ch.addPoint(Point(0,0));
    for(int i=1;i<=q;i++)
    {
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        a=(a+last)%1000000+1;
        b=(b+last)%1000000+1;
        if(k==1)ch.addPoint(Point(a,b));
        else
        {
            Frac x=Frac(b,a);
            if(ch.getY(x)<=Frac(m,a))printf("YES\n"),last=i;
            else printf("NO\n");
        }
    }
    return 0;
}