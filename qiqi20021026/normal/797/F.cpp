#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 5030
#define LL long long
#define abs(x) ((x)>=0?(x):-(x))

LL n,m,a[N],f[N][N],s[N],g[N],q[N];
struct node{
	LL x,c;
	bool operator < (const node s) const{return x<s.x;}
}b[N];

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (LL i=1;i<=m;i++) scanf("%lld%lld",&b[i].x,&b[i].c);
	sort(a+1,a+n+1); sort(b+1,b+m+1);
	memset(f[0],0x3f,sizeof f[0]); f[0][0]=0;
	for (LL i=1;i<=m;i++){
		for (int j=1;j<=n;j++) s[j]=s[j-1]+abs(a[j]-b[i].x);
		int tt=1,ww=1; q[1]=0;
		for (LL j=1;j<=n;j++){
			while (tt<=ww && q[tt]<j-b[i].c) tt++;
			while (tt<=ww && f[i-1][j]-s[j]<=f[i-1][q[ww]]-s[q[ww]]) ww--;
			q[++ww]=j;
			f[i][j]=s[j]+f[i-1][q[tt]]-s[q[tt]];
		}
	}
	printf("%lld\n",(f[m][n]==0x3f3f3f3f3f3f3f3f)?-1:f[m][n]);
	
	return 0;
}