#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define N 305
#define INF 0x7fffffff
using namespace std;
int n,m,t,tu,tp,td,pi,pii,pj,pjj;
int U[N][N],D[N][N],L[N][N],R[N][N],a[N][N];
int cal(int x,int y) {if(x==y)return tp;return x<y?tu:td;}
int main() {
	int ans=INF;
	scanf("%d%d%d",&n,&m,&t);scanf("%d%d%d",&tp,&tu,&td);
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
	rep(i,1,n) rep(j,1,m) {
		if(i!=1)U[i][j]=U[i-1][j]+cal(a[i-1][j],a[i][j]);
		if(i!=1)D[i][j]=D[i-1][j]+cal(a[i][j],a[i-1][j]);
		if(j!=1)L[i][j]=L[i][j-1]+cal(a[i][j-1],a[i][j]);
		if(j!=1)R[i][j]=R[i][j-1]+cal(a[i][j],a[i][j-1]);
	}
	rep(i,1,n) rep(j,1,m) rep(ii,i+2,n) rep(jj,j+2,m) {
		int lr=L[i][jj]-L[i][j]+R[ii][jj]-R[ii][j],ud=D[ii][j]-D[i][j]+U[ii][jj]-U[i][jj];
		if (ans>abs(lr+ud-t)) {
			pii=ii;pi=i;pjj=jj;pj=j;
			ans=abs(lr+ud-t);
		}
	}
	printf("%d %d %d %d\n",pi,pj,pii,pjj);
	return 0;
}