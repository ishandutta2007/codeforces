#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
};
pair<int,Point>p[MAXN];
vector<vector<int> >res;
int fa[MAXN],la[MAXN],mi[MAXN],mx[MAXN],my[MAXN];
void Init(int n)
{
    for(int i=0;i<n;i++)fa[i]=i;
}
int Find(int x)
{
    return x==fa[x] ? x : fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    fa[x]=y;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    res.resize(n);
    for(int i=0;i<n;i++)
        res[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int a;
            scanf("%d",&a);
            p[i*m+j]=make_pair(a,Point(i,j));
        }
    sort(p,p+n*m);
    Init(n*m);
    memset(la,-1,sizeof(la));
    int l=0,r=0;
    while(l<n*m)
    {
        while(r<n*m && p[r].first==p[l].first)r++;
        for(int i=l;i<r;i++)
        {
            if(i>l && p[i].second.x==p[i-1].second.x)Union(i,i-1);
            if(~la[p[i].second.y])Union(i,la[p[i].second.y]);
            la[p[i].second.y]=i;
        }
        for(int i=l;i<r;i++)
        {
            int t=Find(i);
            mi[t]=max(mi[t],mx[p[i].second.x]);
            mi[t]=max(mi[t],my[p[i].second.y]);
        }
        for(int i=l;i<r;i++)
        {
            int t=Find(i);
            res[p[i].second.x][p[i].second.y]=mi[t]+1;
            mx[p[i].second.x]=mi[t]+1;
            my[p[i].second.y]=mi[t]+1;
        }
        while(l<r)la[p[l++].second.y]=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
    return 0;
}