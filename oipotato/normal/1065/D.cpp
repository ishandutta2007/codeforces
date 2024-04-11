#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int dx[8]={-2,-2,-1,-1,1,1,2,2};
const int dy[8]={-1,1,-2,2,-2,2,-1,1};
//1  knight
//2  bishop
//3  rook
pair<int,int>ans[3],tmp[3],d[310][310],pos[110],ANS;
int id[11][11][4],a[11][11],n,tot;
void add(int x,int y,pair<int,int>z){d[x][y]=d[y][x]=min(d[x][y],z);}
void update(pair<int,int>&ans,pair<int,int>x,pair<int,int>y)
{
    x.first+=y.first;
    x.second+=y.second;
    ans=min(ans,x);
}
int main()
{
    scanf("%d",&n);
    rep(i,n)rep(j,n){scanf("%d",&a[i][j]);pos[a[i][j]]=mp(i,j);rep(k,3)id[i][j][k]=++tot;}
    rep(i,tot)rep(j,tot)d[i][j]=mp(10,10);
    rep(i,tot)d[i][i]=mp(0,0);
    rep(i,n)rep(j,n)
    {
        rep(k,3)rep(p,3)add(id[i][j][k],id[i][j][p],mp(1,1));
        for(int k=0;k<8;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(1<=x&&x<=n&&1<=y&&y<=n)add(id[i][j][1],id[x][y][1],mp(1,0));
        }
        for(int k=-1;k<=1;k+=2)
        for(int p=-1;p<=1;p+=2)
        {
            int x=i+k,y=j+p;
            for(;1<=x&&x<=n&&1<=y&&y<=n;x+=k,y+=p)add(id[i][j][2],id[x][y][2],mp(1,0));
        }
        rep(k,n)add(id[i][j][3],id[k][j][3],mp(1,0)),add(id[i][j][3],id[i][k][3],mp(1,0));
    }
    rep(k,tot)rep(i,tot)rep(j,tot)if(i!=j&&j!=k&&k!=j)update(d[i][j],d[i][k],d[k][j]);
    rep(i,n*n-1)
    {
        int a=pos[i].first,b=pos[i].second;
        int x=pos[i+1].first,y=pos[i+1].second;
        rep(j,3)tmp[j]=mp(10*n*n,10*n*n);
        rep(j,3)rep(k,3)update(tmp[j],ans[k],d[id[a][b][k]][id[x][y][j]]);
        rep(j,3)ans[j]=tmp[j];
    }
    ANS=mp(10*n*n,10*n*n);
    rep(i,3)ANS=min(ANS,ans[i]);
    printf("%d %d\n",ANS.first,ANS.second);
	return 0;
}