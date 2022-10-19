#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 120000

const LL mod=998244353;
LL n,m,x,y,z,sum,pw00[N],pw01[N],pw10[N],pw11[N],a[1<<18],b[1<<18],c[1<<18];

struct FWT{
	LL f[1<<18];
	void fwt(){
		for (LL i=0;i<m;++i){
			LL t=1<<i;
			for (LL j=0;j<1<<m;j+=t<<1){
				LL *f1=f+j,*f2=f+j+t;
				for (LL k=0;k<t;++k){
					LL x=f1[k],y=f2[k];
					f1[k]=(x+y)%mod; f2[k]=(x-y+mod)%mod;
				}
			}
		}
	}
}F,F1,F2,F3;

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&x,&y,&z);
	pw00[0]=pw01[0]=pw10[0]=pw11[0]=1;
	pw00[1]=(x+y+z)%mod; pw01[1]=(x-y+z)%mod; pw10[1]=(-x+y+z)%mod; pw11[1]=(-x-y+z)%mod;
	for (LL i=2;i<=n;++i){
		pw00[i]=pw00[i-1]*pw00[1]%mod;
		pw01[i]=pw01[i-1]*pw01[1]%mod;
		pw10[i]=pw10[i-1]*pw10[1]%mod;
		pw11[i]=pw11[i-1]*pw11[1]%mod;
	}
	for (LL i=1;i<=n;++i){
		scanf("%lld%lld%lld",a+i,b+i,c+i);
		a[i]^=c[i]; b[i]^=c[i]; sum^=c[i];
		++F1.f[a[i]]; ++F2.f[b[i]]; ++F3.f[a[i]^b[i]];
	}
	F1.fwt(); F2.fwt(); F3.fwt();
	LL i4=inv(4);
	for (LL i=0;i<1<<m;++i){
		LL A=n,B=F1.f[i],C=F2.f[i],D=F3.f[i];
		LL s00=((A+B+C+D)%mod*i4%mod+mod)%mod;
		LL s01=((A+B-C-D)%mod*i4%mod+mod)%mod;
		LL s10=((A-B+C-D)%mod*i4%mod+mod)%mod;
		LL s11=((A-B-C+D)%mod*i4%mod+mod)%mod;
		F.f[i]=(pw00[s00]*pw01[s01]%mod*pw10[s10]%mod*pw11[s11]%mod+mod)%mod;
	}
	F.fwt();
	for (LL i=0,ii=inv(1<<m);i<1<<m;++i)
		printf(i==(1<<m)-1?"%lld\n":"%lld ",F.f[i^sum]*ii%mod);
	
	return 0;
}