#include <stdio.h>
#include <algorithm>
#define MN 300000
typedef long long LL;
const LL INF = 0x3fffffffffffffff;

int n,q,a[MN+5];

struct node{
	LL ans[2][2];
}T[MN*4+5];

void modify(int k,int l,int r,int p){
	if(l==r){
		T[k].ans[0][0] = 0;
		T[k].ans[1][1] = 0;
		T[k].ans[0][1] = -a[p];
		T[k].ans[1][0] = a[p];
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) modify(k<<1,l,mid,p);
	else modify(k<<1|1,mid+1,r,p);
	for(int s=0;s<=1;s++){
		for(int t=0;t<=1;t++){
			T[k].ans[s][t] = std::max(
				T[k<<1].ans[s][0]+T[k<<1|1].ans[0][t],
				T[k<<1].ans[s][1]+T[k<<1|1].ans[1][t]
			);
		}
	}
}

void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		modify(1,1,n,i);
	}
	printf("%lld\n",std::max(T[1].ans[1][0],T[1].ans[1][1]));
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		std::swap(a[x],a[y]);
		modify(1,1,n,x);
		modify(1,1,n,y);
		printf("%lld\n",std::max(T[1].ans[1][0],T[1].ans[1][1]));
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}