#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;

int n,m,a[MN+5];
LL pa[MN+5],mx[MN+5];

int bins(int x){
	int l=1,r=n,mid;
	while(l<=r){
		mid = (l+r)>>1;
		if(mx[mid]>=x)
			r = mid-1;
		else
			l = mid+1;
	}
	return l-1;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		pa[i] = pa[i-1] + a[i];
		mx[i] = std::max(mx[i-1],pa[i]);
	}
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		if(pa[n]<=0){
			if(x>mx[n]){
				printf("%d ",-1);
			}else{
				printf("%d ",bins(x));
			}
		}else{
			LL r = std::max((x-mx[n]+pa[n]-1)/pa[n],0ll);
			printf("%lld ",r*n+bins(x-r*pa[n]));
		}
	}
	puts("");
}

int main(){
	mx[0] = -1e18;
	int T; scanf("%d",&T);
	while(T--) solve();
}