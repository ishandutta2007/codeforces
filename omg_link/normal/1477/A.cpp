#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;

int n;
LL k,a[MN+5];

LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}

void solve(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	std::sort(a+1,a+1+n);
	LL g = a[2]-a[1];
	for(int i=3;i<=n;i++)
		g = gcd(g,a[i]-a[i-1]);
	puts((k-a[1])%g?"NO":"YES");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}