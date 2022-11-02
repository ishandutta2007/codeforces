#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

#define LL long long

inline LL read(){
	LL x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL MAXN = 300000;
const LL INF = 2147483647;
const LL MAX = 1000000;

LL T; LL mx[MAXN<<3],sum[MAXN<<3];
char str[6]; pair<LL,LL> kt[MAXN+1];
int ls[MAXN<<3],rs[MAXN<<3]; int cnt;
LL tag[MAXN<<3];

inline void pd(LL rt){
	if(!tag[rt]) return ;
	if(ls[rt]) mx[ls[rt]]-=tag[rt],tag[ls[rt]]+=tag[rt];
	if(rs[rt]) mx[rs[rt]]-=tag[rt],tag[rs[rt]]+=tag[rt];
	tag[rt]=0;	
} inline void update(LL rt){
	sum[rt]=sum[ls[rt]]+sum[rs[rt]]; mx[rt]=max(mx[ls[rt]],mx[rs[rt]]);
} inline LL Query(LL rt,LL l,LL r,LL L,LL R){
	if(!rt) return 0; if(L<=l&&R>=r) return mx[rt]; LL mid=(l+r)>>1,ans=0; pd(rt);
	if(L<=mid) ans=max(ans,Query(ls[rt],l,mid,L,R));
	if(R>mid) ans=max(ans,Query(rs[rt],mid+1,r,L,R)); return ans;
} inline void Add(int &rt,LL l,LL r,LL x,LL b,LL n,LL s){
	if(!rt) rt=++cnt; if(l==r) { mx[rt]=(n>0?x+s+b-1:0); sum[rt]+=b*n; return ;} pd(rt);
	LL mid=(l+r)>>1; if(x<=mid) Add(ls[rt],l,mid,x,b,n,s+sum[rs[rt]]);
	else Add(rs[rt],mid+1,r,x,b,n,s); update(rt); return ;
} inline LL Querys(int rt,LL l,LL r,LL L,LL R){
	if(!rt) return 0; if(L<=l&&R>=r) return sum[rt]; LL mid=(l+r)>>1,ans=0; pd(rt);
	if(L<=mid) ans+=Querys(ls[rt],l,mid,L,R); if(R>mid) ans+=Querys(rs[rt],mid+1,r,L,R);
	return ans;
} inline void Addk(int rt,LL l,LL r,LL L,LL R,LL x){
	if(L>R) return ;
	if(!rt) return ; if(L<=l&&R>=r) {mx[rt]-=x; tag[rt]+=x; return ;} int mid=(l+r)>>1; pd(rt);
	if(L<=mid) Addk(ls[rt],l,mid,L,R,x); if(R>mid) Addk(rs[rt],mid+1,r,L,R,x); update(rt); return ;
}
int root,tot;

int main(){
	//freopen("a.txt","r",stdin);
	T=read();
	while(T--){
		scanf("%s",str); ++tot;
		if(str[0]=='?'){
			LL n=read(); 
			//cout<<"gg:"<<Query(root,1,MAX,1,n)<<" "<<Querys(root,1,MAX,n+1,MAX)<<" "<<mx[1]<<" "<<mx[25]<<endl;
			printf("%I64d\n",max(Query(root,1,MAX,1,n)-Querys(root,1,MAX,n+1,MAX)-n+1,0LL));
		} else if(str[0]=='+'){
			LL x=read(),b=read();
			kt[tot]=make_pair(x,b);
			Add(root,1,MAX,x,b,1,0);
			Addk(root,1,MAX,1,x-1,-b);
		} else{
			LL x=read();
			Add(root,1,MAX,kt[x].first,kt[x].second,-1,0);
			Addk(root,1,MAX,1,kt[x].first-1,kt[x].second);
		}
	}
	return 0;
}