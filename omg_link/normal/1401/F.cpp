#include <stdio.h>
#define MN (1<<18)
typedef long long LL;

int n,q;

struct segmentTree{
	LL T[MN*2+5];
	int opt2[20],opt3[20];
	void set(int k,int lvl,int p,int w){
		if(lvl==0){
			T[k] = w;
			return;
		}
		int v = (1<<(lvl-1));
		int flip = opt2[lvl]^opt3[lvl];
		if(p<=v){
			set((k<<1)^flip,lvl-1,p,w);
		}else{
			set((k<<1|1)^flip,lvl-1,p-v,w);
		}
		T[k] = T[k<<1] + T[k<<1|1];
	}
	void set(int p,int w){
		set(1,n,p,w);
	}
	LL query(int k,int lvl,int l,int r){
		if(l==1&&r==(1<<lvl)) return T[k];
		int v = (1<<(lvl-1));
		int flip = opt2[lvl]^opt3[lvl];
		if(r<=v) return query((k<<1)^flip,lvl-1,l,r);
		if(l>v) return query((k<<1|1)^flip,lvl-1,l-v,r-v);
		return query((k<<1)^flip,lvl-1,l,v)+query((k<<1|1)^flip,lvl-1,1,r-v);
	}
	LL query(int l,int r){
		return query(1,n,l,r);
	}
}T;

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,a;i<=(1<<n);i++){
		scanf("%d",&a);
		T.set(i,a);
	}
	for(int opt,x,y;q--;){
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				scanf("%d%d",&x,&y);
				T.set(x,y);
				break;
			}
			case 2:{
				scanf("%d",&x);
				for(int i=x;i>=1;i--)
					T.opt2[i] ^= 1;
				break;
			}
			case 3:{
				scanf("%d",&x);
				T.opt3[x+1] ^= 1;
				break;
			}
			case 4:{
				scanf("%d%d",&x,&y);
				printf("%lld\n",T.query(x,y));
				break;
			}
		}
	}
}