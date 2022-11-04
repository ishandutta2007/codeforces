#include<bits/stdc++.h>
using namespace std;
typedef double db;

const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

inline db cal(int n,int m,int r,int x,int y)
{
    int lenx=min(n-r+1,x)-max(1,x-r+1)+1;
    int leny=min(m-r+1,y)-max(1,y-r+1)+1;
    return 1.0*lenx/(n-r+1)*leny/(m-r+1);
}

inline bool check(int n,int m,pair<int,int> loc)
{
    return loc.first>=1 && loc.first<=n && loc.second>=1 && loc.second<=m;
}

set<pair<int,int> > vis;

struct node
{
    pair<int,int> loc;
    db val;
    bool operator < (const node &rhs)const
    {
        return val<rhs.val;
    }
};

int main()
{
    int n,m,r,k;
    scanf("%d%d%d%d",&n,&m,&r,&k);
//    for(int i=1;i<=n;i++,printf("\n"))
//        for(int j=1;j<=m;j++)
//            printf("%.2f ",cal(n,m,r,i,j));
    priority_queue<node> pq;
    vis.insert({r,r});
    pq.push({{r,r},cal(n,m,r,r,r)});
    db res=0;
    while(k--)
    {
        pair<int,int> now=pq.top().loc;
        res+=pq.top().val;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            pair<int,int> tmp={now.first+dir[i][0],now.second+dir[i][1]};
            if(!check(n,m,tmp) || vis.find(tmp)!=vis.end())continue;
            vis.insert(tmp);
            pq.push({tmp,cal(n,m,r,tmp.first,tmp.second)});
        }
    }
    printf("%.10f\n",res);
    return 0;
}