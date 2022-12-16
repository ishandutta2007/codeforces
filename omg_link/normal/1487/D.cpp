#include <stdio.h>

void solve(){
	int n;
	scanf("%d",&n);
	int l=1,r=1e9,mid;
	while(l<=r){
		mid = (l+r)>>1;
		long long tmid = 2*mid+1;
		long long t = (1ll*tmid*tmid+1)/2;
		if(t<=n)
			l = mid+1;
		else
			r = mid-1;
	}
	printf("%d\n",r);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}