#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
struct chess
{
    int x,y,ty;
    chess(){}
    chess(int _x,int _y,int _ty):x(_x),y(_y),ty(_ty){}
    bool operator < (const chess &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
};
inline int getId(char x)
{
    if(x=='B')return 0;
    if(x=='R')return 1;
    if(x=='Q')return 2;
    return -1;
}
set<chess>st[4];
int main()
{
    int n,ox,oy;
    scanf("%d%d%d",&n,&ox,&oy);
    for(int i=1;i<=n;i++)
    {
        char ty[5];
        int x,y;
        scanf("%s%d%d",ty,&x,&y);
        if(y==oy)st[0].insert(chess(x,y,getId(*ty)));
        if(x==ox)st[1].insert(chess(x,y,getId(*ty)));
        if(x+y==ox+oy)st[2].insert(chess(x,y,getId(*ty)));
        if(x-y==ox-oy)st[3].insert(chess(x,y,getId(*ty)));
    }
    bool isok=0;
    for(int i=0;i<4;i++)
    {
        auto itr=st[i].lower_bound(chess(ox,oy,0)),pre=itr,nxt=itr;
        if(nxt!=st[i].end())isok|=(nxt->ty!=(i>=2));
        if(pre!=st[i].begin())isok|=((--pre)->ty!=(i>=2));
    }
    return 0*printf("%s",(isok ? "YES" : "NO"));
}