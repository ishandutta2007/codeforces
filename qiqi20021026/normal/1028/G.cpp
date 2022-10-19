#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 30000

LL x,f[10][N];

int main(){
	for (LL i=1;i<=10000;++i) f[1][i]=i;
	for (LL i=2;i<=5;++i)
		for (LL j=1;j<=10000;++j){
			for (LL k=j+1,t=j;k;--k){
				if (t>=10000){f[i][j]+=f[i-1][10000]*k+k; break;}
				f[i][j]+=f[i-1][t]+1; t+=f[i-1][t]+1;
			}
			--f[i][j];
		}
	LL i=5,j,s=0;
	while (--i){
		j=min(s+1,10000LL);
		printf("%lld ",j);
		for (LL k=1,t=j,p=s;k<=j;++k){
			printf(k==j?"%lld\n":"%lld ",f[i][t]+p+1);
			p+=f[i][t]+1; t+=f[i][t]+1;
			t=min(t,10000LL);
		}
		fflush(stdout);
		scanf("%lld",&x);
		if (x==-1) return 0;
		if (x==0) continue;
		for (LL k=1,t=j;k<=j;++k){
			s+=f[i][t]+1; t+=f[i][t]+1;
			t=min(t,10000LL);
			if (k==x) break;
		}
	}
	j=min(s+1,10000LL);
	printf("%lld ",j);
	for (LL i=1;i<=j;++i) printf(i==j?"%lld\n":"%lld ",s+i);
	fflush(stdout);
	
	return 0;
}