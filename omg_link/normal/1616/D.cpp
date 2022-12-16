#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 50000

using std::min,std::max;

using ll = long long;

int n,a[MN+5],f[MN+5];
ll pre[MN+5];

struct ddz_t{
	int top;
	int mem[MN+5];
	
	void init(){
		top = 0;
	}
	
	void insert(int x){
		if(x<0) return;
		while(top>0&&pre[x]>=pre[mem[top]]) --top;
		mem[++top] = x;
	}
	
	int bins(ll v){
		int l=1,r=top;
		while(l<=r){
			int mid = (l+r)>>1;
			if(pre[mem[mid]]>v)
				l = mid+1;
			else
				r = mid-1;
		}
		if(r==0) return -1;
		else return mem[r];
	}
	
	void print(){
		printf("size: %d\n",top);
		for(int i=1;i<=top;i++)
			printf("%d%c",mem[i]," \n"[i==top]);
	}
	
}ddz;

struct T_t{
	int T[MN*4+5];
	
	void init(){
		memset(T,0x3f,sizeof(T));
	}
	
	void insert(int k,int l,int r,int p,int w){
		T[k] = min(T[k],w);
		if(l==r) return;
		int mid = (l+r)>>1;
		if(p<=mid) insert(k<<1,l,mid,p,w);
		else insert(k<<1|1,mid+1,r,p,w);
	}
	
	int query(int k,int l,int r,int L,int R){
		if(l==L&&r==R) return T[k];
		int mid = (l+r)>>1;
		if(R<=mid) return query(k<<1,l,mid,L,R);
		if(L>mid) return query(k<<1|1,mid+1,r,L,R);
		return min(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
	}
	
}T;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int x;
	scanf("%d",&x);
	for(int i=1;i<=n;i++){	
		a[i] -= x;
		pre[i] = pre[i-1]+a[i];
	}
	memset(f,0x3f,sizeof(f));
	ddz.init();
	T.init();
	f[0] = 0;
	T.insert(1,0,n,0,f[0]);
	int l = 0;
	for(int i=1;i<=n+1;i++){
		ddz.insert(i-3);
		l = max(l,ddz.bins(pre[i-1])+1);
		//printf("bins %lld ret %d\n",pre[i-1],ddz.bins(pre[i-1]));
		//printf("%d: [%d,%d]\n",i,l,i-1);
		f[i] = T.query(1,0,n,l,i-1)+1;
		T.insert(1,0,n,i,f[i]);
	}
	printf("%d\n",n-f[n+1]+1);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}