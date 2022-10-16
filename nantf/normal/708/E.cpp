#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1515,maxk=222222,mod=1000000007;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,p,k,pre[2][maxn],suf[2][maxn],cur,fac[maxk],inv[maxk],invfac[maxk],ans,pw1[maxk],pw2[maxk];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int C(int n,int m){
	if(n<m || n<0 || m<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	n=read();m=read();
	p=read();p=1ll*p*qpow(read(),mod-2)%mod;
	k=read();
	fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1;
	FOR(i,2,k){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		invfac[i]=1ll*invfac[i-1]*inv[i]%mod;
	}
	pw1[0]=pw2[0]=1;
	FOR(i,1,2*k){
		pw1[i]=1ll*pw1[i-1]*p%mod;
		pw2[i]=1ll*pw2[i-1]*(1-p+mod)%mod;
	}
	cur=1;
	FOR(i,1,m) FOR(j,i,m) if(i-1<=k && m-j<=k){
		int x=1ll*C(k,i-1)*C(k,m-j)%mod*pw1[i-1+m-j]%mod*pw2[2*k-(i-1+m-j)]%mod;
		pre[0][j]=(pre[0][j]+x)%mod;
		suf[0][i]=(suf[0][i]+x)%mod;
	}
	FOR(i,1,m) pre[0][i]=(pre[0][i-1]+pre[0][i])%mod;
	ROF(i,m,1) suf[0][i]=(suf[0][i+1]+suf[0][i])%mod;
	FOR(_,2,n){
		FOR(i,1,m) pre[cur][i]=suf[cur][i]=0;
		int s1=0,s2=0;
		FOR(j,1,m){
			if(j-1<=k){
				s1=(s1+1ll*C(k,j-1)*pw1[j-1]%mod*pw2[k-(j-1)])%mod;
				s2=(s2+1ll*C(k,j-1)*pw1[j-1]%mod*pw2[k-(j-1)]%mod*pre[cur^1][j-1])%mod;
			}
			if(m-j<=k){
				int c=1ll*C(k,m-j)%mod*pw1[m-j]%mod*pw2[k-(m-j)]%mod;
				int s=(pre[cur^1][m]-suf[cur^1][j+1]+mod)%mod;
				pre[cur][j]=(pre[cur][j]+1ll*c*(1ll*s*s1%mod-s2+mod))%mod;
			}
		}
		s1=s2=0;
		ROF(i,m,1){
			if(m-i<=k){
				s1=(s1+1ll*C(k,m-i)*pw1[m-i]%mod*pw2[k-(m-i)])%mod;
				s2=(s2+1ll*C(k,m-i)*pw1[m-i]%mod*pw2[k-(m-i)]%mod*suf[cur^1][i+1])%mod;
			}
			if(i-1<=k){
				int c=1ll*C(k,i-1)%mod*pw1[i-1]%mod*pw2[k-(i-1)]%mod;
				int s=(pre[cur^1][m]-pre[cur^1][i-1]+mod)%mod;
				suf[cur][i]=(suf[cur][i]+1ll*c*(1ll*s*s1%mod-s2+mod))%mod;
			}
		}
		FOR(i,1,m) pre[cur][i]=(pre[cur][i-1]+pre[cur][i])%mod;
		ROF(i,m,1) suf[cur][i]=(suf[cur][i+1]+suf[cur][i])%mod;
		cur^=1;
	}
	printf("%d\n",pre[cur^1][m]);
}