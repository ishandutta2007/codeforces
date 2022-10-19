#include<bits/stdc++.h>

using namespace std;

#define LD long double
#define N 300000

int n,m,k,t;
LD ans,fac[N];

LD C(int x,int y){
	return fac[x]-fac[y]-fac[x-y];
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fac[0]=0; for (int i=1;i<=m;++i) fac[i]=fac[i-1]+logl(i);
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j){
			int t=n*(i+j)-i*j;
			if (t<=k){
				LD tmp=C(n,i)+C(n,j)+C(m-t,k-t)-C(m,k);			
				ans=min((LD)1e99,ans+expl(tmp));
			}
		}
	printf("%.12Lf\n",ans);
	
	return 0;
}