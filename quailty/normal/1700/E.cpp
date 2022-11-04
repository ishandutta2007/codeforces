#include<bits/stdc++.h>
using namespace std;
const int dir[5][2]={{0,1},{1,0},{0,-1},{-1,0},{0,0}};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    auto inside=[&](int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    };
    auto check=[&](int x,int y)
    {
        if(a[x][y]==1)return 1;
        for(int d=0;d<4;d++)
        {
            int tx=x+dir[d][0],ty=y+dir[d][1];
            if(inside(tx,ty) && a[tx][ty]<a[x][y])return 1;
        }
        return 0;
    };
    vector<pair<int,int>> bad;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!check(i,j))bad.emplace_back(i,j);
    if(bad.empty())return 0*printf("0\n");
    if(bad.size()>5u)return 0*printf("2\n");
    set<pair<pair<int,int>,pair<int,int>>> st;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int d=0;d<5;d++)
            {
                pair<int,int> u={i,j},v={bad[0].first+dir[d][0],bad[0].second+dir[d][1]};
                if(u==v || !inside(v.first,v.second))continue;
                swap(a[u.first][u.second],a[v.first][v.second]);
                bool isok=1;
                for(int d=0;d<5;d++)
                {
                    int tx=u.first+dir[d][0],ty=u.second+dir[d][1];
                    if(inside(tx,ty))isok&=check(tx,ty);
                }
                for(int d=0;d<5;d++)
                {
                    int tx=v.first+dir[d][0],ty=v.second+dir[d][1];
                    if(inside(tx,ty))isok&=check(tx,ty);
                }
                for(size_t k=0;k<bad.size();k++)
                    isok&=check(bad[k].first,bad[k].second);
                swap(a[u.first][u.second],a[v.first][v.second]);
                if(isok)st.insert({min(u,v),max(u,v)});
            }
    if(!st.empty())printf("1 %zu\n",st.size());
    else printf("2\n");
    return 0;
}