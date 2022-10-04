#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
typedef long long LL;
inline LL Pow(LL B,LL E,LL M){if(!E)return 1;if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}

const int Mod = 1000000007;

LL n; int k;
LL ps[10005]; int a[10005],pc;
int p[105],q[105];
int iv[105];

int main(){
	scanf("%lld%d",&n,&k);
	LL nn=n;
	for(LL i=2;i*i<=nn;++i){
		if(nn%i)continue;
		ps[++pc]=i;
		while(nn%i==0)++a[pc],nn/=i;
	}if(nn>1)ps[++pc]=nn,a[pc]=1;
	F(i,1,100)iv[i]=Pow(i,Mod-2,Mod);
	int ans=1;
	F(i,1,pc){
		memset(p,0,sizeof p);
		p[a[i]]=1;
		F(j,1,k){
			memset(q,0,sizeof q);
			F(l,0,a[i]) F(ll,0,l) q[ll]=(q[ll]+(LL)p[l]*iv[l+1])%Mod;
			swap(p,q);
		}
		int s=0;
		F(j,0,a[i])s=(s+(LL)Pow(ps[i],j,Mod)*p[j])%Mod;
		ans=(LL)ans*s%Mod;
	}printf("%d\n",ans);
	return 0;
}