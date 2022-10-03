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
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,q;
int a[MN][MN],b[MN][MN];
int qx[MN*MN],qy[MN*MN],l,r;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
	scanf("%d%d%d",&n,&m,&q);
	F(i,1,n)F(j,1,m)scanf("%1d",&a[i][j]),a[i][j]^=(i+j)&1,b[i][j]=-1;
	l=1,r=0;
	F(i,1,n)F(j,1,m){
		int o=0;
		F(d,0,3){
			int nx=i+dx[d],ny=j+dy[d];
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(a[nx][ny]!=a[i][j])o=1;
		}
		if(o)++r,qx[r]=i,qy[r]=j,b[i][j]=1;
	}
	while(l<=r){
		int x=qx[l],y=qy[l];++l;
		F(d,0,3){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(a[nx][ny]==a[x][y]&&b[nx][ny]==-1)
				b[nx][ny]=b[x][y]+1,
				++r,qx[r]=nx,qy[r]=ny;
		}
	}
	while(q--){
		int x,y;ll t;
		scanf("%d%d%lld",&x,&y,&t);
		if(b[x][y]==-1||t<b[x][y])printf("%d\n",a[x][y]^((x+y)&1));
		else printf("%d\n",(a[x][y]^(int)((t-b[x][y]+1)&1))^((x+y)&1));
	}
	return 0;
}