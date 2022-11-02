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
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
#define nd second
#define ds first
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 502000
int n,m,F[M],a[M],iv[M],ans[M],hv;
struct eqv{
	int K[3],con,id[3],sz;
	inline void gv(int i){
		con=mod-1,sz=3-(i==m-1)-(i==0);
		if(!i){	
			id[0]=0,K[0]=mns(mul(n-2,iv[n-1]),1);
			id[1]=1,K[1]=iv[n-1];
			return;
		}
		id[0]=i-1,K[0]=mul(i,iv[m]);
		id[1]=i,K[1]=mns(mul(mul(n-2,iv[n-1]),mul(m-i,iv[m])),1);
		if(i+1<m) id[2]=i+1,K[2]=mul(iv[n-1],mul(m-i,iv[m]));
	}
	inline void opt(){
		debug(sz)el;
		for(int i=0;i<sz;i++) printf("%d F[%d]    ",K[i],id[i]);
		printf(" =  %d\n",con);fgx;
	}
	inline void tms(int k){for(int i=0;i<sz;i++) K[i]=mul(K[i],k);con=mul(con,k);}
}p[M];
inline void check(eqv &w){
	if(!w.sz) return; eqv tmp=w; w.sz=0;
	for(int i=0;i<tmp.sz;i++) if(ans[tmp.id[i]]>-1) dec(w.con,mul(tmp.K[i],ans[tmp.id[i]]));
	for(int i=0;i<tmp.sz;i++) if(ans[tmp.id[i]]==-1&&tmp.K[i]>0) w.K[w.sz]=tmp.K[i],w.id[w.sz]=tmp.id[i],w.sz++;
	if(w.sz==1){w.sz=0,ans[w.id[0]]=mul(w.con,qpow(w.K[0],mod-2));hv++;return;}
}
inline void elm(eqv &A,eqv &B){
	if(A.sz>B.sz){elm(B,A);return;} if(!A.sz) return;
	if(A.id[0]==B.id[0]){
		int kb=B.K[0],ka=A.K[0];
		B.tms(ka),A.tms(kb),dec(B.con,A.con);
		for(int i=0,j=0;i<A.sz;i++){
			while(B.id[j]!=A.id[i]) j++;
			dec(B.K[j],A.K[i]);
			assert(j<B.sz);
		}
	} check(B);
}
int main(){
	n=read(),iv[1]=1;
	for(int i=1;i<=n;i++) a[i]=read(),m+=a[i];
	if(m==1){puts("0");return 0;}
	memset(ans,-1,sizeof(ans)),ans[m]=0;
	for(int i=2;i<=max(n,m);i++) iv[i]=mul(mod-mod/i,iv[mod%i]);
	for(int i=0;i<m;i++) p[i].gv(i);//,debug(i)sp,p[i].opt();fgx;fgx;
	for(int i=0;i+1<m;i++){
		check(p[i]),check(p[i+1]);
		if(p[i].sz==2) elm(p[i],p[i+1]);
	}
	for(int i=m-1;i>=0;--i) check(p[i]); int res=0;
	// for(int i=0;i<m;i++) p[i].opt();
	for(int i=1;i<=n;i++) upd(res,ans[a[i]]);
	dec(res,mul(n-1,ans[0]));
	// for(int i=0;i<m;i++) debug(i)sp,debug(ans[i])el;
	res=mul(res,iv[n]);
	printf("%d\n",res);
	return 0;
}