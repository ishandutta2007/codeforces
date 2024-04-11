#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int Q;
int f[1000001],g[10][1000001];
int main(){
	for(int i=1;i<=1000000;++i){
		int p=i;
		f[i]=1;
		while(p){
			if(p%10!=0) f[i]*=p%10;
			p/=10;
		}
	}
	F(i,1,1000000){
		int p=i;
		while(p>=10){
			p=f[p];
		}
		g[p][i]=1;
	}
	F(j,1,9)
	F(i,1,1000000) g[j][i]+=g[j][i-1];
	scanf("%d",&Q);
	while(Q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",g[k][r]-g[k][l-1]);
	}
	return 0;
}