#include <bits/stdc++.h>
#define N 1001000
using namespace std;
typedef long long ll;

long long P,f[N];
long long fac[N+3],inv[N+3];
long long mi(long long x,long long y,long long P){
	long long res=1;
	while (y){
		if (y&1) res=res*x%P;
		x=x*x%P; y>>=1;
	}
	return res;
}

void fuckjyw()
{
	fac[0]=1;
	for(int i=1;i<P;i++)fac[i]=(fac[i-1]*i)%P;
	
	inv[P-1]=mi(fac[P-1],P-2,P);
	for(int i=P-2;i>=1;i--)inv[i]=inv[i+1]*(long long)(i+1)%P;
}

long long C(int n,int m)
{
	if (n==m||m==0)return 1ll;
	long long ans=(fac[n]*inv[m])%P;
	ans=ans*inv[n-m]%P; return ans;
}
int main(){

	int n,m; long long a,Q; scanf("%d%d%I64d%I64d",&m,&n,&a,&Q);

	long long k=a;
	for (P=2;P<N;P++){
		k=k*a%Q; if (k==1) break;
	}
	//P=999983;

	fuckjyw();
	/*for (int n=1;n<=15;n++){
		int m=15;*/
	long long res=0;
	for (int i=1;i<=min(m,n);i++){
		res+=C(n,i-1); if (res>=P) res-=P;
		f[i]=res;
	}
	res=mi(2,n,P);
	for (int i=min(m,n)+1;i<=m;i++) f[i]=res;

	for (int i=1;i<=m;i++) f[i]=mi(a,f[i],Q);
	for (int i=m;i>1;i--) printf("%I64d ",f[i]);
	printf("%I64d\n",f[1]);
	

	return 0;
}