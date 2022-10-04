#include<algorithm>
#include<cstdio>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n,q;
int x[300001],y[300001],opt[300001];
int sq[600001],cnt;
int siz[600001];
int sz[2097155],dat[2097155],lzy[2097155];
void build(int i,int l,int r){
	if(l==r) {sz[i]=siz[l]; return;}
	int mid=l+r>>1;
	build(i<<1,l,mid), build(i<<1|1,mid+1,r);
	sz[i]=sz[i<<1]+sz[i<<1|1];
}
void init(){
	scanf("%d%d",&n,&q);
	F(i,1,q) scanf("%d%d%d",x+i,y+i,opt+i), sq[++cnt]=x[i]-1, sq[++cnt]=y[i];
	sort(sq+1,sq+cnt+1);
	int Cnt=cnt, lst=-1; cnt=0;
	F(i,1,Cnt) if(sq[i]!=lst) sq[++cnt]=sq[i], lst=sq[i];
	F(i,1,cnt-1) siz[i]=sq[i+1]-sq[i];
	F(i,1,q) x[i]=lower_bound(sq+1,sq+cnt+1,x[i]-1)-sq, y[i]=lower_bound(sq+1,sq+cnt+1,y[i])-sq-1;
	cnt--;
}
inline void pushdown(int i){
	if(lzy[i]==1) dat[i<<1]=sz[i<<1], dat[i<<1|1]=sz[i<<1|1], lzy[i<<1]=lzy[i<<1|1]=1;
	if(lzy[i]==2) dat[i<<1]=dat[i<<1|1]=0, lzy[i<<1]=lzy[i<<1|1]=2;
	lzy[i]=0;
}
void M(int a,int b,int i,int l,int r,int typ){
	if(a<=l&&r<=b) {dat[i]=(typ==1?(sz[i]):0); lzy[i]=typ; return;}
	if(r<a||b<l) return;
	pushdown(i);
	int mid=l+r>>1;
	M(a,b,i<<1,l,mid,typ), M(a,b,i<<1|1,mid+1,r,typ);
	dat[i]=dat[i<<1]+dat[i<<1|1];
}
int main(){
	init();
	build(1,1,cnt);
	F(i,1,q){
		if(opt[i]==1) M(x[i],y[i],1,1,cnt,1);
		else M(x[i],y[i],1,1,cnt,2);
		printf("%d\n",n-dat[1]);
	}
	return 0;
}