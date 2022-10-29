#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int mod=998244353;
const int N=1<<20;
int jie[N],inv[N],A[N],B[N],w[N],invw[N],len,pos[N],f[N],g[N];
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
inline int add(int a,const int &b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,const int &b){a-=b;return a<0?a+mod:a;}
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void INI(){
	jie[0]=1;
	inv[0]=inv[1]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N){
		jie[i]=mul(jie[i-1],i);
		inv[i]=mul(inv[i],inv[i-1]);
	}
	int G=quick(3,(mod-1)/N),IG=quick(G,mod-2);f[0]=g[0]=1;
	rep(i,1,N)f[i]=mul(f[i-1],G),g[i]=mul(g[i-1],IG);
}
inline void init(){
	int op=len>>1,k=N/len;
	for(int i=0,j=0;i<len;++i,j+=k){
		w[i]=f[j];invw[i]=g[j];
		pos[i]=pos[i>>1]>>1|(i&1?op:0);
	}
}
inline void NTT(int *a,int *omg){
	rep(i,0,len)if(i<pos[i])swap(a[i],a[pos[i]]);
	for(int i=2;i<=len;i<<=1){
		int m=i>>1;
		for(int *p=a;p!=a+len;p+=i){
			rep(j,0,m){
				int t=mul(omg[len/i*j],p[j+m]);
				p[j+m]=sub(p[j],t);
				p[j]=add(p[j],t);
			}
		}
	}
}
int C(int n,int m){
	if(n<0||m<0||m>n)return 0;
	return mul(mul(jie[n],inv[m]),inv[n-m]);
}
int main(){
	INI();
	int n,L=1;
	scanf("%d",&n);	
	len=1<<14;
	init();
	A[0]=1;
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		int nL=L+a-b,j,k;
		for(j=b-L+1,k=0;a+b-j>=b-L+1;++j,++k){
			B[k]=C(a+b,j);
		}
		for(;k<len;++k)B[k]=0;
		rep(i,L,len)A[i]=0;
	//	rep(i,0,L)cout<<A[i]<<' ';
	//	cout<<"iniA\n";
		NTT(A,w),NTT(B,w);
		rep(i,0,len)B[i]=mul(B[i],A[i]);NTT(B,invw);
		int inv=quick(len,mod-2);
	//
	//	cout<<"ans\n";
		rep(i,0,nL)A[i]=mul(B[i+L-1],inv);
	//	cout<<nL<<"L\n";
	//	rep(i,0,nL)cout<<A[i]<<' ';
	//	cout<<"A\n";
		L=nL;
	}
	int ans=0;
	rep(i,0,L)ans=add(ans,A[i]);
	printf("%d\n",ans);
}