#include <stdio.h>
#define MN 200000
typedef long long ll;

void solve(){
	int n;
	scanf("%d",&n);
	ll sum = 0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		sum += a;
	}
	ll p1 = sum%n;
	ll p2 = n-p1;
	printf("%lld\n",p1*p2);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}