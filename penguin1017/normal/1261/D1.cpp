#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define vi vector<int>
#define ll long long
#define pb push_back
using namespace std;
const int mod=998244353;
const int N=1<<12;
int A[N],B[N],w[N],inv[N],len,len1,len2,pos[N],res[N],f[N],g[N];
void init(){
	int op=len>>1,k=N/len;
	for(int i=0,j=0;i<len;++i,j+=k){
		w[i]=f[j];inv[i]=g[j];
		pos[i]=pos[i>>1]>>1|(i&1?op:0);
	}
}
void NTT(int *a,int *omg){
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
int quick(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1; 
	}
	return res;
}
int a[N],n,k;
vi solve(int l,int r){
	if(l==r){
		vi g;
		if(a[l]==a[(l+1)%n])g.pb(0),g.pb(k);
		else g.pb(1),g.pb(k-2),g.pb(1);
		return g;
	}
	int mid=l+r>>1;
	vi g1=solve(l,mid);
	vi g2=solve(mid+1,r);
	int len1=g1.size(),len2=g2.size();
	len=1;while(len<len1+len2)len<<=1;
	rep(i,0,len1)A[i]=g1[i];
//	cout<<"A\n";
	rep(i,0,len2)B[i]=g2[i];
//	cout<<"B\n";
//	cout<<l<<' '<<r<<' '<<len1<<' '<<len2<<"check\n";
	init();
	NTT(A,w);NTT(B,w);rep(i,0,len)A[i]=1ll*A[i]*B[i]%mod;NTT(A,inv);
	int lenni=quick(len,mod-2);
	vi g;
	rep(i,0,len1+len2-1)g.pb(1ll*A[i]*lenni%mod);
//	cout<<"G\n";
	rep(i,0,len)A[i]=B[i]=0;
//	system("pause");
	return g;
}
int main(){
	int num=quick(3,(mod-1)/N),ni=quick(num,mod-2);f[0]=g[0]=1;
	rep(i,1,N)f[i]=1ll*f[i-1]*num%mod,g[i]=1ll*g[i-1]*ni%mod;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%d",&a[i]);
	vi g=solve(0,n-1);
	ll ans=0;
	rep(i,0,g.size())if(i>n)ans+=g[i];
	ans%=mod;
	printf("%lld",ans); 
}