#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define vi vector<int>
#define pb push_back
#define ll long long
#define sz size()
using namespace std;
const int mod=998244353;
const int N=1<<18;
int A[N],B[N],w[N],inv[N],len,len1,len2,pos[N],res[N],f[N],g[N],p[(int)3e6];
int quick(ll a,int b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
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
vi solve(int l,int r){
	if(l==r){
		vi g;
		rep(i,0,p[l]+1)g.pb(1);
		return g;
	}
	int mid=l+r>>1;
	vi L=solve(l,mid),R=solve(mid+1,r);
	len1=L.sz;len2=R.sz;
	len=1;
	while(len<len1+len2)len<<=1;
	rep(i,0,len1)A[i]=L[i];
	rep(i,0,len2)B[i]=R[i];
	init();
	NTT(A,w),NTT(B,w);rep(i,0,len)A[i]=1ll*A[i]*B[i]%mod,B[i]=0;NTT(A,inv);
	int lenni=quick(len,mod-2);
	vi g;
	rep(i,0,len1+len2-1){
		int res=1ll*A[i]*lenni%mod;
		g.pb(res);
		A[i]=0;
	}
	return g;
}
int main()
{
	int num=quick(3,(mod-1)/N),ni=quick(num,mod-2);f[0]=g[0]=1;
	rep(i,1,N)f[i]=1ll*f[i-1]*num%mod,g[i]=1ll*g[i-1]*ni%mod;
	int n,val;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&val),++p[val];
	int cnt=0;
	rep(i,0,(int)3e6)if(p[i])p[cnt++]=p[i];
	vi g=solve(0,cnt-1);
	printf("%d\n",g[n/2]);
}