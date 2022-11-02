#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
#define M 3000200
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,m,mi[M],sum[M]; 
int p[M],pos[M],q[M];
inline void pushup(int x){
	sum[x]=sum[x<<1]+sum[x<<1|1];
	mi[x]=min(mi[x<<1],mi[x<<1|1]+sum[x<<1]);
}
inline void mdf(int x,int l,int r,int pos,int val){
	if(l==r){sum[x]+=val,mi[x]+=val;return;} int mid=((l+r)>>1);
	(pos<=mid)?mdf(x<<1,l,mid,pos,val):mdf(x<<1|1,mid+1,r,pos,val); pushup(x);
}
int nowmi,nowsum,rem;
inline void qry(int x,int l,int r,int ls,int rs){
	if(ls<=l&&r<=rs){nowmi=min(nowmi,nowsum+mi[x]),nowsum+=sum[x]; return;}
	if(r<ls||rs<l) return; int mid=((l+r)>>1);
	qry(x<<1,l,mid,ls,rs),qry(x<<1|1,mid+1,r,ls,rs);
}
inline void solve(int x,int l,int r){
	if(l==r){rem+=sum[x];rem=max(rem,0);return;}
	if(rem+mi[x]>=0){rem+=sum[x];return;}
	int mid=((l+r)>>1); if(rem+mi[x<<1]<0) rem=-mi[x<<1];
	rem+=sum[x<<1],solve(x<<1|1,mid+1,r);return;
}
inline void calc(int x,int l,int r,int ls,int rs){
	if(ls<=l&&r<=rs){solve(x,l,r);return;} if(r<ls||rs<l) return;
	int mid=((l+r)>>1); calc(x<<1,l,mid,ls,rs),calc(x<<1|1,mid+1,r,ls,rs);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) p[i]=read(),pos[p[i]]=i;
	for(int i=1;i<=n;i++) q[i]=read();
	printf("%d",n);
	for(int i=1,las=n;i<n;i++){
		mdf(1,1,n,q[i],-1);
		while(true){
			nowmi=nowsum=0,qry(1,1,n,pos[las],n);
			rem=0,calc(1,1,n,1,pos[las]-1);
			if(rem+nowmi>=0) break;
			mdf(1,1,n,pos[las],1),las--;
		}
		printf(" %d",las);
	} puts("");
	return 0;
}