#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;

int n,a[MN+5];
LL ans;

int bins(int l,int r,int w){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]&(1<<w))
			r = mid-1;
		else
			l = mid+1;
	}
	return l;
}

void ccc(int x){
	ans += 1ll*x*(x-1)/2;
}

void calc(int l,int r,int w){
	if(w==-1){
		ccc(r-l+1);
		return;
	}
	int p = bins(l,r,w);
	calc(l,p-1,w-1);
	ccc(r-p+1);
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	ans = 0;
	calc(1,n,29);
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}