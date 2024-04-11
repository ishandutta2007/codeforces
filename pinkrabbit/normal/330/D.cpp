#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m;
char a[MN][MN];
int sx,sy,tx,ty;
int qx[MN*MN],qy[MN*MN];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int v[MN][MN],ds[MN][MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n)F(j,1,m)if(a[i][j]=='S')sx=i,sy=j;else if(a[i][j]=='E')tx=i,ty=j;
	int l=1,r=1;
	qx[1]=tx,qy[1]=ty;
	v[tx][ty]=1;
	while(l<=r){
		int ux=qx[l],uy=qy[l];
		++l;
		F(d,0,3){
			int vx=ux+dx[d],vy=uy+dy[d];
			if(vx<1||vx>n||vy<1||vy>m)continue;
			if(a[vx][vy]=='T')continue;
			if(v[vx][vy])continue;
			v[vx][vy]=1;
			ds[vx][vy]=ds[ux][uy]+1;
			++r,qx[r]=vx,qy[r]=vy;
		}
	}
//	F(i,1,n)F(j,1,m)printf("%d%c",ds[i][j]," \n"[j==m]);
	int ans=0;
	F(i,1,n)F(j,1,m)if(isdigit(a[i][j])&&v[i][j]&&ds[i][j]<=ds[sx][sy])ans+=a[i][j]-'0';
	printf("%d\n",ans);
	return 0;
}