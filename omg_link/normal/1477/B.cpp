#include <stdio.h>
#include <string.h>
#define MN 200000

int n,q,l[MN+5],r[MN+5];
int s[MN+5],f[MN+5];

struct segT{
	struct node{
		int cnt[2],tag;
		void clear(){
			tag = -1;
			cnt[0] = cnt[1] = 0;
		}
	}T[MN*4+5];
	
	struct res{
		int cnt[2];
		res(int x=0,int y=0){
			this->cnt[0] = x;
			this->cnt[1] = y;
		}
		res operator + (const res& that)const{
			return res(this->cnt[0]+that.cnt[0],this->cnt[1]+that.cnt[1]);
		}
	};
	
	void pushtag(int k,int l,int r,int w){
		T[k].cnt[w] = r-l+1;
		T[k].cnt[w^1] = 0;
		T[k].tag = w;
	}
	
	void pushdown(int k,int l,int r){
		if(T[k].tag!=-1){
			int mid = (l+r)>>1;
			pushtag(k<<1,l,mid,T[k].tag);
			pushtag(k<<1|1,mid+1,r,T[k].tag);
			T[k].tag = -1;
		}
	}
	
	void modify(int k,int l,int r,int L,int R,int w){
		if(l==L&&r==R){
			pushtag(k,l,r,w);
			return;
		}
		int mid = (l+r)>>1;
		pushdown(k,l,r);
		if(R<=mid) modify(k<<1,l,mid,L,R,w);
		else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
		else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
		T[k].cnt[0] = T[k<<1].cnt[0]+T[k<<1|1].cnt[0];
		T[k].cnt[1] = T[k<<1].cnt[1]+T[k<<1|1].cnt[1];
	}
	
	res query(int k,int l,int r,int L,int R){
		if(l==L&&r==R)
			return res(T[k].cnt[0],T[k].cnt[1]);
		int mid = (l+r)>>1;
		pushdown(k,l,r);
		if(R<=mid) return query(k<<1,l,mid,L,R);
		if(L>mid) return query(k<<1|1,mid+1,r,L,R);
		return query(k<<1,l,mid,L,mid)+query(k<<1|1,mid+1,r,mid+1,R);
	}
}T;

void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%1d",&f[i]);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=n;i++)
		T.modify(1,1,n,i,i,f[i]);
	for(int i=q;i>=1;i--){
		segT::res c = T.query(1,1,n,l[i],r[i]);
		if(2*c.cnt[0]<r[i]-l[i]+1){
			T.modify(1,1,n,l[i],r[i],1);
		}else if(2*c.cnt[1]<r[i]-l[i]+1){
			T.modify(1,1,n,l[i],r[i],0);
		}else{
			puts("NO");
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(!T.query(1,1,n,i,i).cnt[s[i]]){
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}