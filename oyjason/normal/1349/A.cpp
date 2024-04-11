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
#define M 200200
int pri[M],fs[M],n,tot;
vector<int>t[M];
bool isp[M];
int main(){
	// for(int Cas=read();Cas;--Cas) solve();
	memset(isp,true,sizeof(isp));
	for(int i=2;i<M;i++){
		if(isp[i]) pri[++tot]=i,fs[i]=i;
		for(int j=1;j<=tot&&pri[j]*i<M;j++){
			isp[pri[j]*i]=false;
			fs[pri[j]*i]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		while(x>1){
			int k=fs[x],cnt=0;
			while(x%k==0) x/=k,cnt++;
			t[k].pb(cnt);
		}
	}
	LL ans=1;
	for(int i=2;i<M;i++) if((int)t[i].size()>=n-1){
		if((int)t[i].size()==n){
			int mi=100,sc=100;
			for(int j=0,TP=t[i].size();j<TP;j++){
				if(t[i][j]<=mi) sc=mi,mi=t[i][j];
				else sc=min(sc,t[i][j]);
			}
			while(sc>0) sc--,ans*=(LL)i;
		}
		else{
			int mi=100;
			for(int j=0,TP=t[i].size();j<TP;j++) mi=min(mi,t[i][j]);
			while(mi) mi--,ans*=(LL)i;
		}

	}
	printf("%lld\n",ans);
	return 0;
}