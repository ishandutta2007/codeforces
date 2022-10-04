#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define x first
#define y second

int n,q,k;
int a[5][200005];

#define mid (l+r>>1)

int mx[32][524288];
void Mdf(int o,int i,int l,int r,int p,int x){
	if(l==r) {mx[o][i]=x; return;}
	if(p<=mid) Mdf(o,i<<1,l,mid,p,x);
	else Mdf(o,i<<1|1,mid+1,r,p,x);
	mx[o][i]=max(mx[o][i<<1],mx[o][i<<1|1]);
}
int Qur(int o,int i,int l,int r,int a,int b){
	if(r<a||b<l) return -99999999;
	if(a<=l&&r<=b) return mx[o][i];
	return max(Qur(o,i<<1,l,mid,a,b),Qur(o,i<<1|1,mid+1,r,a,b));
}

inline void Mdf(int i){
	F2(j,0,1<<k){
		int s=0;
		F2(l,0,k) s+=(j>>l&1)?a[l][i]:-a[l][i];
		Mdf(j,1,1,n,i,s);
	}
}

int Ans[32];

int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n) F2(j,0,k) scanf("%d",&a[j][i]);
	F(i,1,n) Mdf(i);
	scanf("%d",&q);
	F(i,1,q){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int id;
			scanf("%d",&id);
			F2(j,0,k) scanf("%d",&a[j][id]);
			Mdf(id);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			F2(j,0,1<<k) Ans[j]=Qur(j,1,1,n,l,r);
			int A=0;
			F2(j,0,1<<k) A=max(A,Ans[j]+Ans[(1<<k)-1-j]);
			printf("%d\n",A);
		}
	}
	return 0;
}