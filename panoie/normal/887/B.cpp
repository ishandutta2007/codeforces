#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
using namespace std;
#define ll long long
#define rt register int
#define reep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
int n, a[22][22];
bool f[1005];
int main() {
	scanf("%d", &n);
	rep(i, 1, n) rep(j, 1, 6) scanf("%d", &a[i][j]);
	if(n==1){
		rep(i, 1, 6) f[a[1][i]]=1;
	}
	else if(n==2){
		rep(i, 1, 6) f[a[1][i]]=1;
		rep(i, 1, 6) f[a[2][i]]=1;
		rep(i, 1, 6) rep(j, 1, 6) f[a[1][i]*10+a[2][j]]=1, f[a[2][i]*10+a[1][j]]=1;
	}
	else{
		rep(i, 1, 6) f[a[1][i]]=1;
		rep(i, 1, 6) f[a[2][i]]=1;
		rep(i, 1, 6) f[a[3][i]]=1;
		rep(i, 1, 6) rep(j, 1, 6)
			f[a[1][i]*10+a[2][j]]=1, f[a[2][i]*10+a[1][j]]=1,
			f[a[1][i]*10+a[3][j]]=1, f[a[3][i]*10+a[1][j]]=1,
			f[a[3][i]*10+a[2][j]]=1, f[a[2][i]*10+a[3][j]]=1;
//		printf("%d\n", a[2][5]);
		rep(i, 1, 6) rep(j, 1, 6) rep(k, 1, 6)
			f[a[1][i]*100+a[2][j]*10+a[3][k]]=1,
			f[a[1][i]*100+a[3][j]*10+a[2][k]]=1,
			f[a[2][i]*100+a[1][j]*10+a[3][k]]=1,
			f[a[2][i]*100+a[3][j]*10+a[1][k]]=1,
			f[a[3][i]*100+a[1][j]*10+a[2][k]]=1,
			f[a[3][i]*100+a[2][j]*10+a[1][k]]=1;
	}
	rep(i, 1, 999) if(!f[i]){
		printf("%d", i-1);
		break;
	}
	return 0;
}