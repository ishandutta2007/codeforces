#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
#define pii pair<int,int>
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200020
#define maxn 31700
int pri[M],fs[M],tot,n; bool isp[maxn];
inline void fail(){puts("-1");exit(0);}
inline void sieve(){
	memset(isp,true,sizeof(isp));
	for(int i=2;i<maxn;i++){
		if(isp[i]) pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<maxn;j++){
			isp[pri[j]*i]=false;
			if(i%pri[j]==0) break;
		}
	}
}
#define mod1 1000000009
#define mod2 1000000007
#define mod3 998244353
inline LL _pow1(LL x,LL sq){x%=mod1;LL res=1;for(;sq;sq>>=1,x=x*x%mod1)if(sq&1)res=res*x%mod1;return res;}
inline LL _pow2(LL x,LL sq){x%=mod2;LL res=1;for(;sq;sq>>=1,x=x*x%mod2)if(sq&1)res=res*x%mod2;return res;}
inline LL _pow3(LL x,LL sq){x%=mod3;LL res=1;for(;sq;sq>>=1,x=x*x%mod3)if(sq&1)res=res*x%mod3;return res;}
inline bool check(LL a1,LL b1,LL c1,LL a2,LL b2,LL c2){
	if(a1*_pow1(b1,c1)%mod1!=a2*_pow1(b2,c2)%mod1) return false;
	if(a1*_pow2(b1,c1)%mod2!=a2*_pow2(b2,c2)%mod2) return false;
	if(a1*_pow3(b1,c1)%mod3!=a2*_pow3(b2,c2)%mod3) return false;
	return true;
}
int t[70],ga,gb,gc; int num[70],m;
inline bool inq(int a,int b,int _a,int _b,int _c){
	int _tms=0,rem=a,A=a,B=b,_A=_a,_B=_b; m=0;
	while(_tms<_c&&rem%_b==0) rem/=_b,_tms++;
	if(_tms==_c&&rem==_a) return true;
	if(_a==1&&(_c==0||_b==1)) return false;
	if(b==1) return false;
	for(int i=1;i<=tot;i++) if(b%pri[i]==0){
		int hv=0,dn=0,d=0;
		while(b%pri[i]==0) d++,b/=pri[i];
		while(a%pri[i]==0) dn++,a/=pri[i];
		while(_b%pri[i]==0) hv+=_c,_b/=pri[i];
		while(_a%pri[i]==0) hv++,_a/=pri[i];
		if(hv<=dn) return false; if((hv-dn)%d>0) return false;
		int k=(hv-dn)/d; return check(A,B,k,_A,_B,_c);
	} int hv=0,dn=0;
	while(a%b==0) dn++,a/=b;
	while(_a%b==0) hv++,_a/=b;
	while(_b%b==0) hv+=_c,_b/=b;
	if(hv<=dn) return false;
	return check(A,B,hv-dn,_A,_B,_c);
}

inline void calc1(int a1,int b1,int a2,int b2,int num){
	int A1=a1,B1=b1,A2=a2,tar=0,fir=0,d=0;
	while(A1%num==0) A1/=num,fir++;
	while(B1%num==0) B1/=num,d++;
	while(A2%num==0) A2/=num,tar++;
	if(fir>tar) fail(); if((tar-fir)%d>0) fail();
	ga=a1,gb=b1,gc=(tar-fir)/d;
}
inline bool solve(int a1,int b1,int a2,int b2){
	//debug(a1)sp,debug(b1)sp,debug(a2)sp,debug(b2)el;
	int _a1=a1,_b1=b1,_a2=a2,_b2=b2,las1=0,las2=0,lasp=-1,q1,q2;
	for(int i=1;i<=tot;i++){
		int hv1=0,hv2=0;
		while(b1%pri[i]==0) hv1++,b1/=pri[i];
		while(b2%pri[i]==0) hv2++,b2/=pri[i];
		//if(i<=10) debug(i)sp,debug(pri[i])sp,debug(hv1)sp,debug(hv2)sp,debug(b1)sp,debug(b2)el;
		if(!hv1&&!hv2) continue;
		if(!hv1) swap(hv1,hv2),swap(_a1,_a2),swap(_b1,_b2);
		if(!hv2){calc1(_a1,_b1,_a2,_b2,pri[i]);return true;}
		if(las1*hv2==las2*hv1){las1=hv1,las2=hv2;continue;}
		for(int k1=0;k1<=900;k1++) for(int k2=0;k2<=900;k2++)
			if(check(_a1,_b1,k1,_a2,_b2,k2)){ga=_a1,gb=_b1,gc=k1;return true;}
		fail();
	}
	//fgx;
	if(b1>1||b2>1){
		if(b2!=1&&b1!=b2){calc1(_a2,_b2,_a1,_b1,b2);return true;}
		if(b2==1){calc1(_a1,_b1,_a2,_b2,b1);return true;}
		if(las1==las2) return false;
		for(int k1=0;k1<=900;k1++) for(int k2=0;k2<=900;k2++)
			if(check(_a1,_b1,k1,_a2,_b2,k2)){ga=_a1,gb=_b1,gc=k1;return true;}
		fail();
	} return false;
}

pii p[M];
#define A first
#define B second
int con,dt[M],fir[M],rm[M];
inline int getans(int a,int b,int c){
	for(int i=1;i<=n;i++) if(!inq(p[i].A,p[i].B,a,b,c)) return -1;
	return mul(a%mod,qpow(b,c));
}

int main(){
	n=read(),sieve();
	for(int i=1;i<=n;i++) p[i].A=read(),p[i].B=read();
	sort(p+1,p+n+1),n=unique(p+1,p+n+1)-p-1;
	if(n==1){printf("%d\n",p[1].A);return 0;}
	for(int i=1;i<=n;i++) if(p[i].B==1){printf("%d\n",getans(p[i].A,1,0));return 0;}
	//fgx;
	for(int i=1;i<n;i++) if(solve(p[i].A,p[i].B,p[i+1].A,p[i+1].B)){printf("%d\n",getans(ga,gb,gc));return 0;}
	//fgx;
	bool same=true;
	for(int i=1;i<n;i++) same&=(p[i].B==p[i+1].B);
	if(same) con=p[1].B;
	else{
		con=1;
		for(int i=1;i<=tot;i++){
			int tms=0;
			for(int k=1,now=0;k<=n;k++,now=0){
				for(int rem=p[k].B;rem%pri[i]==0;rem/=pri[i],now++);
				tms=__gcd(tms,now);
			} while(tms--) con*=pri[i];
		}
	}
	//debug(con)el;
	for(int i=1;i<=n;i++){
		while(p[i].B>1) p[i].B/=con,dt[i]++;
		while(p[i].A%con==0) p[i].A/=con,fir[i]++;
		if(i>1&&p[i].A!=p[i-1].A) fail(); rm[i]=fir[i]%dt[i];
		//debug(i)sp,debug(fir[i])sp,debug(rm[i])sp,debug(dt[i])el;
	} LL md=1,now=0;
	for(int i=1;i<=n;i++){
		bool ok=false;
		for(int k=0;k<dt[i];now+=md,k++) if(now%dt[i]==rm[i]){ok=true;break;}
		if(!ok) fail(); md=md*(LL)dt[i]/__gcd(md,(LL)dt[i]);
	}
	//debug(now)el;
	for(int i=1;i<=n;i++) while(now<fir[i]) now+=md;
	printf("%d\n",mul(p[1].A,qpow(con,now)));
	return 0;
}