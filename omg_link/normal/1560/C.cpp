#include <stdio.h>

int bins(int k){
	int l=1,r=32768;
	while(l<=r){
		int mid = (l+r)>>1;
		if(mid*mid>=k)
			r = mid-1;
		else
			l = mid+1;
	}
	return l;
}

void solve(){
	int k;
	scanf("%d",&k);
	int n = bins(k);
	k -= (n-1)*(n-1);
	if(k<=n){
		printf("%d %d\n",k,n);
	}else{
		k -= n;
		printf("%d %d\n",n,n-k);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}