#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define vi vector<int>
#define ll long long
#define pb push_back
using namespace std;
const int mod=998244353;
const int N=1<<19;
int A[N],B[N],w[N],inv[N],len,len1,len2,pos[N],res[N],f[N],g[N];
inline void init(){
	int op=len>>1,k=N/len;
	for(int i=0,j=0;i<len;++i,j+=k){
		w[i]=f[j];inv[i]=g[j];
		pos[i]=pos[i>>1]>>1|(i&1?op:0);
	}
}
inline void NTT(int *a,int *omg){
	rep(i,0,len)if(i<pos[i])swap(a[i],a[pos[i]]);
	for(int i=2;i<=len;i<<=1){
		int m=i>>1;
		for(int *p=a;p!=a+len;p+=i){
			rep(j,0,m){
				int t=1ll*omg[len/i*j]*p[j+m]%mod;
				p[j+m]=p[j]-t;if(p[j+m]<0)p[j+m]+=mod;
				p[j]+=t;if(p[j]>=mod)p[j]-=mod; 
			}
		}
	}
}
inline int quick(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1; 
	}
	return res;
}
int a[N],n,k;
inline vi quickNTT(int *a,int b,int lenth){
	len=1;while(len<lenth)len<<=1;
	res[0]=1;rep(i,1,len)res[i]=0;
	init();
	NTT(res,w);NTT(a,w);
	while(b){
		if(b&1)rep(i,0,len)res[i]=1ll*res[i]*a[i]%mod;
		rep(i,0,len)a[i]=1ll*a[i]*a[i]%mod;
		b>>=1;
	}
	vi g;
	NTT(res,inv);
	int lenni=quick(len,mod-2);
	rep(i,0,lenth)g.pb(1ll*res[i]*lenni%mod);
	return g;
}
int main(){
	int num=quick(3,(mod-1)/N),ni=quick(num,mod-2);f[0]=g[0]=1;
	rep(i,1,N)f[i]=1ll*f[i-1]*num%mod,g[i]=1ll*g[i-1]*ni%mod;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%d",&a[i]);
	int cnt=0;
	rep(i,0,n)if(a[i]^a[(i+1)%n])++cnt;
	A[0]=1,A[1]=k-2,A[2]=1;
	vi g=quickNTT(A,cnt,2*cnt+1);
	ll ans=0;
	rep(i,0,g.size())if(i>cnt)ans+=g[i];
	ans%=mod;
	ans=ans*quick(k,n-cnt)%mod;
	printf("%lld",ans); 
}