#include <stdio.h>
#define MN 100000

using ll = long long;

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool flag = false;
	ll ans = 0;
	for(int i=2;i<=n-1;i++){
		if(a[i]>=2) flag = true;
		ans += (a[i]+1)/2;
	}
	if(n==3&&(a[2]&1)){
		flag = false;
	}
	if(!flag){
		puts("-1");
	}else{
		printf("%lld\n",ans);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}