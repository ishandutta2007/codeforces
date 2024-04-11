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
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 5100
int n,m,L[M],R[M],ct[M];
int kd[M],prd[M],sum[M],rgt[M];
vector<int>hv[M];
int pre[M],ans,mx,suf[M],ar[M];
int t[M];
inline void solve(int k){
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	memset(ar,0,sizeof(ar));
	int tot=0;
	for(int i=0,TP=hv[k].size();i<TP;i++) t[++tot]=hv[k][i];
	for(int i=1;i<=tot;i++){
		int ls=L[t[i]],rs=R[t[i]]; pre[ls]++,suf[rs]++;
		if(ls<rs) ar[ls+1]++,ar[rs]--;
	}
	for(int i=1;i<=m;i++) pre[i]+=pre[i-1],ar[i]+=ar[i-1];
	for(int i=m;i>=0;--i) suf[i]+=suf[i+1];
	for(int i=0;i<=m;i++) if(prd[i]>0){
		int now,gg;
		if(kd[i]!=k){
			now=pre[i]*suf[i]-ar[i],gg=2;
			if(!now) now=add(pre[i],suf[i]),gg=1;
			if(!now) now=1,gg=0;
			assert(now>=0);
		}
		else{
			now=suf[i+1]-(rgt[i]>i),gg=1;
			if(!now) now=1,gg=0;
		}
		prd[i]=mul(prd[i],now),sum[i]+=gg;
	}
}
int main(){
	m=read(),n=read();
	for(int i=1;i<=m;i++) ct[kd[i]=read()]++;
	for(int i=1;i<=n;i++){
		int typ=read(),req=read();
		if(ct[typ]<req){i--,n--;continue;}
		for(int j=1,rem=req;j<=m;j++){
			if(typ==kd[j]) --rem;
			if(!rem){L[i]=j;break;}
		}
		for(int j=m,rem=req;j>=1;j--){
			if(typ==kd[j]) --rem;
			if(!rem){R[i]=j;break;}
		} hv[typ].pb(i),prd[L[i]]=1,sum[L[i]]=1,rgt[L[i]]=R[i];
		//debug(i)sp,debug(L[i])sp,debug(R[i])el;
	}
	if(!n){puts("0 1"); return 0;}
	hv[0].pb(0),prd[0]=sum[0]=1,mx=-1;
	for(int i=0;i<M;i++) if(!hv[i].empty()) solve(i);
	for(int i=0;i<=m;i++) if(sum[i]>1){
		if(mx<sum[i]) mx=sum[i],ans=0;
		if(mx==sum[i]) upd(ans,prd[i]);
	}
	printf("%d %d\n",mx-1,ans);
	return 0;
}