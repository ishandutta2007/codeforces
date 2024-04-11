#include <stdio.h>
#include <algorithm>

int fsqrt(int x){
	int l=0,r=x,mid;
	while(l<=r){
		mid = (l+r)>>1;
		if(1ll*mid*mid<=x)
			l = mid+1;
		else
			r = mid-1;
	}
	return r;
}

void solve(){
	int x,y;
	long long ans = 0;
	scanf("%d%d",&x,&y);
	int t = std::min(fsqrt(x+1),y);
	ans = 1ll*t*(t-1)/2;
	for(int i=t+2;i<=y+1;i++){
		if(x/i==0) break;
		int r = std::min(x/(x/i),y+1);
		ans += 1ll*x/i*(r-i+1);
		i = r;
	}
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}