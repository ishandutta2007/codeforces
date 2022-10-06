#include <bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;
const int MN = 3005;
const int INF = 0x3f3f3f3f;

int n, m, q, k;
int a[MN][MN],b[MN],c;
int a1[MN][MN],a2[MN][MN],c1[MN],c2[MN];

int main() {
	scanf("%d%d",&n,&m);
	F(i,1,n)F(j,1,m)scanf("%d",&a[i][j]);
	F(i,1,n){
		F(j,1,m)b[j]=a[i][j];
		sort(b+1,b+m+1);
		c1[i]=c=unique(b+1,b+m+1)-b-1;
		F(j,1,m)a1[i][j]=lower_bound(b+1,b+c+1,a[i][j])-b;
	}
	F(i,1,m){
		F(j,1,n)b[j]=a[j][i];
		sort(b+1,b+n+1);
		c2[i]=c=unique(b+1,b+n+1)-b-1;
		F(j,1,n)a2[j][i]=lower_bound(b+1,b+c+1,a[j][i])-b;
	}
//	F(i,1,n){F(j,1,m)printf("%d ",a1[i][j]);puts("");}puts("");
//	F(i,1,n){F(j,1,m)printf("%d ",a2[i][j]);puts("");}puts("");
	F(i,1,n){F(j,1,m)printf("%d ",max(a1[i][j],a2[i][j])+max(c1[i]-a1[i][j],c2[j]-a2[i][j]));puts("");}
	return 0;
}