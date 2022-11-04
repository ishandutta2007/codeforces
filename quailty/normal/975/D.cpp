#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200005;

struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
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
        return (*this)*t>0;
    }
};

int main()
{
    int n;
    Point dir;
    scanf("%d%lld%*d",&n,&dir.y),dir.x=1;
    vector<pair<ll,Point> > cro;
    vector<ll> dot;
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%*d%lld%lld",&x,&y);
        Point p=Point(x,y);
        if(p*dir==0)dot.push_back(p^dir);
        else cro.push_back({p*dir,p});
    }
    ll res=1LL*dot.size()*dot.size();
    sort(dot.begin(),dot.end());
    for(int l=0,r=0;l<(int)dot.size();l=r)
    {
        while(r<(int)dot.size() && dot[l]==dot[r])r++;
        res-=1LL*(r-l)*(r-l);
    }
    sort(cro.begin(),cro.end());
    for(int l=0,r=0;l<(int)cro.size();l=r)
    {
        while(r<(int)cro.size() && cro[l].first==cro[r].first)r++;
        vector<Point> t;
        for(int k=l;k<r;k++)
            t.push_back(cro[k].second);
        sort(t.begin(),t.end());
        res+=1LL*t.size()*t.size();
        for(int i=0,j=0;i<(int)t.size();i=j)
        {
            while(j<(int)t.size() && t[i]*t[j]==0)j++;
            res-=1LL*(j-i)*(j-i);
        }
    }
    printf("%lld\n",res);
    return 0;
}