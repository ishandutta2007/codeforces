#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
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

namespace CALC{
	#define mod 1000000007
	inline int add(int x,int y){return ((x+y>=mod)?(x+y-mod):(x+y));}
	inline int mns(int x,int y){return ((x-y<0)?(x-y+mod):(x-y));}
	inline int mul(LL x,LL y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x=((x+y>=mod)?(x+y-mod):(x+y));}
	inline void dec(int &x,int y){x=((x-y<0)?(x-y+mod):(x-y));}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 102000
int n,m,pri[M],fs[M],tot; bool isp[M]; LL ans;
struct st{
	int sz,sta[18],ct[18];
	inline void solve(int rem){
		memset(sta,0,sizeof(sta));
		memset(ct,0,sizeof(ct)),sz=0;
		while(rem>1){
			int k=fs[rem],nw=0;
			while(rem%k==0) rem/=k,nw++;
			nw%=m; if(nw) ++sz,sta[sz]=k,ct[sz]=nw;
		}
	}
	inline void rev(){
		for(int i=1;i<=sz;i++) ct[i]=m-ct[i];
	}
	inline bool operator < (const st&ot)const{
		if(sz!=ot.sz) return sz<ot.sz;
		for(int i=1;i<=sz;i++){
			if(sta[i]!=ot.sta[i]) return sta[i]<ot.sta[i];
			if(ct[i]!=ot.ct[i]) return ct[i]<ot.ct[i];
		} return false;
	}
}w;map<st,int>K;
inline void sieve(){
	memset(isp,true,sizeof(isp));
	for(int i=2;i<M;i++){
		if(isp[i]) pri[++tot]=i,fs[i]=i;
		for(int j=1;j<=tot&&pri[j]*i<M;++j){
			int num=pri[j]*i; isp[num]=false;
			fs[num]=pri[j]; if(i%pri[j]==0) break;
		}
	}
}
int main(){
	n=read(),m=read(),sieve();
	for(int i=1;i<=n;i++){
		int x=read();
		w.solve(x);
		w.rev();
		ans+=K[w];
		w.rev();
		K[w]++;
	}
	printf("%lld\n",ans);
	return 0;
}