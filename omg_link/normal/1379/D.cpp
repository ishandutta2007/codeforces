#include <stdio.h>
#define MN 100000

int n,M,k;
int m[MN+5];
int ansn=0x7fffffff,anst;

struct node{
	int sum,ls,rs;
}T[MN*32];
int Tn = 1;

void add(int k,int l,int r,int p){
	if(l==r){
		T[k].sum ++;
		return;
	}
	int mid = (l+r)>>1;
	if(p<=mid){
		if(!T[k].ls) T[k].ls = (++Tn);
		add(T[k].ls,l,mid,p);
	}else{
		if(!T[k].rs) T[k].rs = (++Tn);
		add(T[k].rs,mid+1,r,p);
	}
	T[k].sum = T[T[k].ls].sum + T[T[k].rs].sum;
}

int query(int k,int l,int r,int L,int R){
	if(!k) return 0;
	if(l==L&&r==R) return T[k].sum;
	int mid = (l+r)>>1;
	if(R<=mid) return query(T[k].ls,l,mid,L,R);
	if(L>mid) return query(T[k].rs,mid+1,r,L,R);
	return query(T[k].ls,l,mid,L,mid)+query(T[k].rs,mid+1,r,mid+1,R);
}

int main(){
	scanf("%d%*d%d%d",&n,&M,&k);
	if(k==1){
		puts("0 0");
		return 0;
	} 
	M>>=1;
	for(int i=1;i<=n;i++){
		scanf("%*d%d",&m[i]);
		if(m[i]>=M) m[i] -= M;
		add(1,0,M-1,m[i]);
	}
	for(int i=1;i<=n;i++){
		//m[i] ~ m[i]+k
		int L = (m[i]+1)%M;
		int R = (m[i]+k-1)%M;
		int tansn;
		if(L<=R) tansn = query(1,0,M-1,L,R);
		else tansn = query(1,0,M-1,L,M-1) + query(1,0,M-1,0,R);
		if(tansn < ansn){
			ansn = tansn;
			anst = m[i];
		}
	}
	printf("%d %d\n",ansn,(anst+k)%M);
	int L = (anst+1)%M;
	int R = (anst+k-1)%M;
	if(L<=R){
		for(int i=1;i<=n;i++)
			if(L<=m[i] && m[i]<=R) printf("%d ",i);
	}else{
		for(int i=1;i<=n;i++)
			if(L<=m[i] || m[i]<=R) printf("%d ",i);
	}
}