#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define n 10
#define ll long long
#define mod 1000003
inline ll qp(ll b,int e){int a=1;for(;e;e>>=1,b=b*b%mod)if(e&1)a=a*b%mod;return a;}
ll m[n+1][n+2],a[n+1];
void gauss(){
	F(i,0,n){
		int b=qp(m[i][i],mod-2);
		F(j,i,n+1)m[i][j]=m[i][j]*b%mod;
		F(j,0,n)if(j!=i){
			int c=m[j][i];
			F(k,i,n+1)m[j][k]=(m[j][k]-m[i][k]*c%mod+mod)%mod;
		}
	}
}
int main(){
	F(i,0,n)printf("? %d\n",i),fflush(stdout),scanf("%lld",&m[i][n+1]);
	F(i,0,n)F(j,0,n)m[i][j]=qp(i,j);
	gauss();
	F(i,0,n)a[i]=m[i][n+1];
	ll ans=-1;
	F2(i,0,mod){
		ll x=0;
		dF(j,n,0)x=(x*i+a[j])%mod;
		if(!x)ans=i;
	}
	printf("! %lld\n",ans),fflush(stdout);
	return 0;
}