#include<bits/stdc++.h>

using namespace std;

typedef int uint;

int n,m,p,a[300];
uint c[300],ans;

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

uint pw(uint x,int y){
	if (y==0) return 1;
	uint t=pw(x*x,y>>1);
	return y&1?t*x:t;
}

int main(){
	scanf("%d%d%d",&n,&m,&p); m=min(m,n-1);
	for (int i=0;i<=m;++i){
		c[i]=1;
		for (int j=1;j<=i;++j) a[j]=j;
		for (int j=1;j<=i;++j){
			int x=n-j+1;
			for (int k=1;k<=i;++k){
				int d=gcd(x,a[k]);
				a[k]/=d; x/=d;
			}
			c[i]=c[i]*x;
		}
	}
	for (int i=1;i<=p;++i){
		uint tmp=0;
		for (int j=0;j<=m;++j)
			tmp+=c[j]*pw(i,j);
		ans^=i*tmp;
	}
	printf("%u\n",ans);
	
	return 0;
}