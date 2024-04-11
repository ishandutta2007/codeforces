#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define LL long long
#define N 120000

LL mod,n,a[N],b[N],sum1,sum2;

LL getint(){
	char ch; LL sum=0;
	for (ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for (;ch>='0' && ch<='9';ch=getchar()) sum=sum*10+ch-'0';
	return sum;
}

LL sig(LL x){return x*(x+1)/2;}

LL sig2(LL x){return x*(x+1)*(2*x+1)/6%mod;}

LL inv(LL x,LL p){return x==1?1:(p-p/x)*inv(p%x,p)%p;}

int main(){
	mod=getint(); n=getint();
	for (LL i=1;i<=n;i++){a[i]=getint(); (sum1+=a[i])%=mod; (sum2+=a[i]*a[i])%=mod;}
	sort(a+1,a+n+1);
	if (n==1){printf("%lld 0\n",a[1]); return 0;}
	if (n==mod){puts("0 1"); return 0;}
	for (LL i=2;i<=n;i++){
		LL d=(a[i]-a[1]+mod)%mod,a1=((sum1-sig(n-1)*d)%mod+mod)*inv(n,mod)%mod;
		LL tmp1=(a1*n+d*sig(n-1))%mod,tmp2=(a1*a1%mod*n+2*a1*d%mod*sig(n-1)+d*d%mod*sig2(n-1))%mod;
		if (tmp1==sum1 && tmp2==sum2){
			LL xb; b[xb=1]=a1;
			for (LL i=1;i<n;i++) b[++xb]=(a1+d*i)%mod; sort(b+1,b+n+1);
			bool flag=1; for (LL i=1;i<=n;i++) if (a[i]!=b[i]){flag=0; break;}
			if (flag){printf("%lld %lld\n",a1,d); return 0;}
		}
	}
	puts("-1");
	
	return 0;
}