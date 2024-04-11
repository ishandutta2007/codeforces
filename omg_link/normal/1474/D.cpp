#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,a[MN+5];

struct segT{
	struct node{
		long long m,s;
	}T[MN*4+5];
	
	void build(int k,int l,int r){
		T[k].m = T[k].s = 0;
		if(l==r) return;
		int mid = (l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	
	void pushup(int k){
		T[k].m = std::min(T[k<<1].m,T[k<<1].s+T[k<<1|1].m);
		T[k].s = T[k<<1].s + T[k<<1|1].s;
	}
	
	void modify(int k,int l,int r,int p,int w){
		if(l==r){
			T[k].m = T[k].s = w;
			return;
		}
		int mid = (l+r)>>1;
		if(p<=mid) modify(k<<1,l,mid,p,w);
		else modify(k<<1|1,mid+1,r,p,w);
		pushup(k);
	}
}T[2];

void upd(int p){
	if(p<1||p>n) return;
	T[p&1].modify(1,1,(n+1)>>1,(p+1)>>1,a[p]-a[p-1]);
}

bool check(){
	if(T[0].T[1].m<0||T[1].T[1].m<0) return false;
	if(T[n&1].T[1].s!=0) return false;
	return true;
}

void solve(){
	scanf("%d",&n);
	T[0].build(1,1,(n+1)>>1);
	T[1].build(1,1,(n+1)>>1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		upd(i);
	}
	if(check()){
		puts("YES");
		return;
	}
	for(int i=2;i<=n;i++){
		std::swap(a[i],a[i-1]);
		upd(i+1),upd(i),upd(i-1),upd(i-2);
		if(check()){
			puts("YES");
			return;
		}
		std::swap(a[i],a[i-1]);
		upd(i+1),upd(i),upd(i-1),upd(i-2);
	}
	puts("NO");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}