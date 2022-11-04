#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300005;
struct Point
{
    static int idx;
    int x[2],id;
    Point(){}
    Point(int _x,int _y,int _id=0)
    {
        x[0]=_x,x[1]=_y,id=_id;
    }
    bool operator < (const Point &t)const
    {
        if(x[idx]==t.x[idx])
        {
            if(x[idx^1]==t.x[idx^1])
                return id<t.id;
            return x[idx^1]<t.x[idx^1];
        }
        return x[idx]<t.x[idx];
    }
}p[MAXN];
int Point::idx=0;
int xx[MAXN<<1];
struct BIT
{
    int n,c[MAXN<<1];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]+=v;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)res+=c[i];
        return res;
    }
}bit;
int main()
{
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x[0],&p[i].x[1]),p[i].id=i;
        xx[cnt++]=p[i].x[0],xx[cnt++]=p[i].x[1];
    }
    sort(xx,xx+cnt);
    cnt=unique(xx,xx+cnt)-xx;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            p[i].x[j]=lower_bound(xx,xx+cnt,p[i].x[j])-xx;
    int res=0,rl=0,rr=0;
    bit.init(cnt);
    for(int l=0,r=0,t=1;l<cnt;l++,r=max(r,l))
    {
        while(t<=n && p[t].x[0]<=l)
            bit.update(cnt-p[t].x[1],1),t++;
        while(r<cnt && bit.query(cnt-r)>=k)r++;
        r--;
        if(r>=l && xx[r]-xx[l]+1>res)
        {
            res=xx[r]-xx[l]+1;
            rl=l;
            rr=r;
        }
    }
    printf("%d\n",res);
    if(res==0)for(int i=1;i<=k;i++)
        printf("%d ",i);
    else
    {
        vector<int>idx;
        for(int i=1;i<=n;i++)
            if(p[i].x[0]<=rl && p[i].x[1]>=rr)idx.push_back(p[i].id);
        for(int i=0;i<k;i++)
            printf("%d ",idx[i]);
    }
    return 0;
}