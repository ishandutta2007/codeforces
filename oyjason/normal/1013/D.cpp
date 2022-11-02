#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 400020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,f[M],sum,sz1[M],sz2[M],u,v,T;
LL fa(LL x){return x==f[x]?x:f[x]=fa(f[x]);}
void merge(LL x,LL y){
	x=fa(x),y=fa(y);
	if(x==y) return;
	f[y]=x,sz1[x]+=sz1[y],sz2[x]+=sz2[y];
}
void write(LL x){
	if(x<0){putchar('-');return write(-x);}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),T=read();
	for(LL i=1;i<=n+m;i++) f[i]=i;
	for(LL i=1;i<=n;i++) sz1[i]=1;
	for(LL i=n+1;i<=m+n;i++) sz2[i]=1;
	while(T--) u=read(),v=read(),merge(u,v+n);
	for(LL i=1;i<=n+m;i++){
		if(fa(i)!=i) continue;
		sum++;
	}
	write(sum-1),putchar('\n');
	return 0;
}
/*

4 3 6
1 2
1 3
2 2
2 3
3 1
3 3

*/