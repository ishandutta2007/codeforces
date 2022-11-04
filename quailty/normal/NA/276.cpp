#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=(1LL<<60)-1;

struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
};

struct ConvexHull
{
    set<Point> st;
    ll area;
    void clear()
    {
        st.clear();
        area=0;
    }
    bool in(const Point &p)const
    {
        if(st.empty())return 0;
        if(p.x<st.begin()->x)return 0;
        if(p.x>(--st.end())->x)return 0;
        auto lef=st.lower_bound(Point(p.x,-INF));
        if(p.x==lef->x)return p.y<=lef->y;
        auto rig=lef--;
        return (p-*lef)*(*rig-*lef)>=0;
    }
    void insert(const Point &p)
    {
        if(in(p))return;
        st.insert(p);
        auto itr=st.lower_bound(p);
        if(itr!=st.begin() && itr!=(--st.end()))
        {
            auto lef=itr;lef--;
            auto rig=itr;rig++;
            area+=(*lef-p)*(*rig-p);
        }
        if(itr==st.begin() && itr!=(--st.end()))
        {
            auto rig=itr;rig++;
            area+=(rig->x-p.x)*(p.y+rig->y);
        }
        if(itr!=st.begin() && itr==(--st.end()))
        {
            auto lef=itr;lef--;
            area+=(p.x-lef->x)*(p.y+lef->y);
        }
        if(itr!=st.begin())
        {
            auto now=itr;now--;
            while(now!=st.begin())
            {
                auto tmp=now;tmp--;
                if((*tmp-p)*(*now-p)>=0)
                {
                    area+=(*tmp-p)*(*now-p);
                    st.erase(now--);
                }
                else break;
            }
            if(now->x==p.x)st.erase(now);
        }
        if(itr!=(--st.end()))
        {
            auto now=itr;now++;
            while(now!=(--st.end()))
            {
                auto tmp=now;tmp++;
                if((*now-p)*(*tmp-p)>=0)
                {
                    area+=(*now-p)*(*tmp-p);
                    st.erase(now++);
                }
                else break;
            }
        }
    }
}up,dw;

int main()
{
    up.clear();
    dw.clear();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
        {
            up.insert(Point(x,y));
            dw.insert(Point(x,-y));
        }
        else
        {
            bool isok=(up.in(Point(x,y)) && dw.in(Point(x,-y)));
            printf("%s\n",(isok ? "YES" : "NO"));
        }
    }
    return 0;
}