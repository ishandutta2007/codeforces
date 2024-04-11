#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}

int n,m;
int phi[150001];
int X[100001],Y[100001];

void init(){
	for(int i=1;i<=100000;++i){
		int x=i;
		phi[i]=i;
		for(int j=2;j*j<=x;++j){
			if(x%j==0){
				phi[i]=phi[i]/j*(j-1);
				while(x%j==0) x/=j;
			}
		}
		if(x!=1)
			phi[i]=phi[i]/x*(x-1);
	}
}

int main(){
	init();
	scanf("%d%d",&n,&m);
	if(m<n-1) return 0*puts("Impossible");
	ll Sum=0;
	F(i,2,n) Sum+=phi[i];
	if(Sum<m) return 0*puts("Impossible");
	puts("Possible");
	m-=n-1;
	F(i,2,n) printf("1 %d\n",i);
	F(i,3,n) if(m){
		F(j,2,i-1) if(m){
			if(Gcd(i,j)==1) --m, printf("%d %d\n",j,i);
			if(!m) break;
		}
		if(!m) break;
	}
	return 0;
}