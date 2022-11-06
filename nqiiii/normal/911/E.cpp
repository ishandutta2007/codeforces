#include<cstdio>
const int maxn=200000;
int n,k,stk[maxn+10],stksz,now=1,a[maxn+10];
bool in[maxn+10];
bool ins(int x){
	if(stksz&&stk[stksz]<x) return 0;
	stk[++stksz]=x; in[x]=1;
	for(;now<=n&&in[now];in[now++]=0) --stksz;
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%d",&a[i]);
		if(!ins(a[i])){
			printf("-1"); return 0;
		}
	}
	for(;now<=n;){
		int top=stksz?stk[stksz]-1:n;
		for(int i=top;i>=now;--i) a[++k]=i,ins(i);
	}
	for(int i=1;i<=n;++i) printf("%d ",a[i]); return 0;
}