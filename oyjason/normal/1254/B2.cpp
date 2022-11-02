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
#define M 1020000
int n,m,tot;
LL pri[M]; bool isp[M];

inline void sieve(){
	memset(isp,true,sizeof(isp));
	for(int i=2;i<M;i++){
		if(isp[i]) pri[++tot]=i;
		for(int j=1;pri[j]*i<M&&j<=tot;++j){
			isp[pri[j]*i]=false;
			if(i%pri[j]==0) break;
		}
	}
}
int A[M];
LL sum,t[100],ans;

inline LL solve(LL w){
	LL dt=0,rm=0,res=0; 
	for(int i=1;i<=n;i++,res+=dt) if(A[i]>0){
		rm=(A[i]+rm)%w;
		dt=min(rm,w-rm);
	} res-=dt;
	return res;
}
int main(){
	// for(int Cas=read();Cas;--Cas) solve();
	n=read();sieve();
	for(int i=1;i<=n;i++) A[i]=read(),sum+=A[i]; LL rem=sum;
	if(sum==1){puts("-1");return 0;}
	for(int i=1;pri[i]*pri[i]<=rem;i++) if(rem%pri[i]==0){
		while(rem%pri[i]==0) rem/=pri[i];
		t[++m]=pri[i];
	} if(rem>1) t[++m]=rem;
	ans=sum*(LL)n;
	for(int i=1;i<=m;i++) ans=min(ans,solve(t[i]));
	printf("%lld\n",ans);
	return 0;
}