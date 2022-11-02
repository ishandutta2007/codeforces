#include <stdio.h>
#define meow(args...) fprintf(stderr, args)
const int N=10005, P=998244353;
long long power(long long a, int b)
{
	long long ans=1;
	for(; b; a=a*a%P, b>>=1) if(b&1) ans=ans*a%P;
	return ans;
}
int fac[N], ref[N];
int main()
{
	int p, s, r;
	scanf("%d%d%d", &p, &s, &r);
	if(r==0) {
		printf("%d\n", (int)power(p, P-2));
		return 0;
	}
	fac[0]=1;
	for(int i=1; i<=p+s; ++i) fac[i]=(long long)fac[i-1]*i%P;
	ref[p+s]=power(fac[p+s], P-2);
	for(int i=p+s; i>=1; --i) ref[i-1]=(long long)ref[i]*i%P;
	int ans=0;
	for(int i=1; i<=s/r && i<=p; ++i) {
		int tmp=(long long)fac[s-i*r+p-1]*fac[p-1]%P*fac[s-r]%P*ref[s-i*r]%P*ref[s-r+p-1]%P*ref[i]%P*ref[p-i]%P;
		if(i&1) ans=(ans+tmp)%P; else ans=(ans+P-tmp)%P;
	}
	printf("%d\n", ans);
	return 0;
}