#include <cstdio>
#include <vector>
const int N=3e5, P=1e9+7;
int n, cnt[N+1];
long long inv[8], f[N+1];
int F() {
	int a=0;
	unsigned char c;
	while((c=getchar()-'0')>9);
	while(a=a*10+c, (c=getchar()-'0')<10);
	return a;
}
int main() {
	n=F();
	for(int i=0; i<n; ++i) ++cnt[F()];
	for(int i=1; i<=N; ++i) for(int j=i<<1; j<=N; j+=i) cnt[i]+=cnt[j];
	inv[1]=1;
	for(int i=2; i<=7; ++i) inv[i]=-P/i*inv[P%i]%P;
	for(int i=1; i<=7&&i<=n; ++i) {
		for(int j=N; j>=1; --j) {
			f[j]=1;
			for(int k=1; k<=i; ++k) f[j]=f[j]*(cnt[j]-k+1ll)%P*inv[k]%P;
			for(int k=2; j*k<=N; ++k) f[j]=(f[j]-f[j*k])%P;
		}
		if(f[1]) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}