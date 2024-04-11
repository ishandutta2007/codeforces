#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353,gen=3,inv2=(mod+1)/2;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,w[maxn],p[maxn],s[maxn],a[maxn],b[maxn],ans[maxn];
int lim,l,wn[maxn],rev[maxn];
void init(int upr){
	for(lim=1,l=0;lim<upr;lim<<=1,l++);
	FOR(i,0,lim-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=1;i<lim;i<<=1){
		int w=qpow(gen,(mod-1)/(i<<1));
		wn[i]=1;
		FOR(k,1,i-1) wn[i+k]=1ll*wn[i+k-1]*w%mod;
	}
}
void dft(int *a){
	static ull b[maxn];
	FOR(i,0,lim-1) b[rev[i]]=a[i];
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1){
				ull x=b[j+k],y=b[i+j+k]*wn[i+k]%mod;
				b[j+k]=x+y;b[i+j+k]=x-y+mod;
			}
	FOR(i,0,lim-1) a[i]=b[i]%mod;
}
void idft(int *a){
	dft(a);
	reverse(a+1,a+lim);
	int linv=qpow(lim,mod-2);
	FOR(i,0,lim-1) a[i]=1ll*a[i]*linv%mod;
}
int c[maxn],d[maxn];
void work(int l1,int r1,int l2,int r2){
	if(r2<=n/3 || l1>n*2/3) return;
	FOR(_,0,1){
/*		FOR(i,l1,r1) FOR(j,l2,r2) if(i%2==_ && j%2!=_){
			ans[(i+j+1)/2]=(ans[(i+j+1)/2]+1ll*a[j]*b[i])%mod;
			if((i+j+1)/2==8) printf("%d %d to %d\n",j,i,(i+j+1)/2);
		}
*/		init(r2-l2+1+r1-l1+1);
		FOR(i,0,lim-1) c[i]=d[i]=0;
		FOR(i,l1,r1) c[i-l1]=i%2==_?b[i]:0;
		FOR(i,l2,r2) d[i-l2]=i%2!=_?a[i]:0;
//		FOR(i,0,lim-1) printf("%d ",c[i]);
//		puts("");
//		FOR(i,0,lim-1) printf("%d ",d[i]);
//		puts("");
		dft(c);dft(d);
		FOR(i,0,lim-1) c[i]=1ll*c[i]*d[i]%mod;
		idft(c);
		FOR(i,l1,r2){
			int x=i*2-1-l1-l2;
			if(x>=0 && x<lim) ans[i]=(ans[i]+c[x])%mod;
		}
	}
}
void solve(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
//	printf("[%d,%d,%d]\n",l,mid,r);
	work(l,mid,mid+1,r);
}
int main(){
	n=read();m=read();
	FOR(i,1,n) w[i]=0;
	FOR(i,n+1,2*n) w[i]=read();
	FOR(i,2*n+1,3*n) w[i]=0;
	FOR(i,1,m) s[p[i]=read()+n]++;
	n*=3;
	FOR(i,1,n) s[i]+=s[i-1];
	FOR(i,0,n) a[i]=qpow(inv2,s[i]),b[i]=qpow(2,s[i]);
//	FOR(x,n/3+1,n*2/3) FOR(i,1,min(x,n-x+1)) ans[x]=(ans[x]+1ll*a[x+i-1]*b[x-i])%mod;
//	FOR(i,0,n) printf("a[%d]=%d,b[%d]=%d\n",i,a[i],i,b[i]);
	solve(0,n);
	int res=0;
	FOR(i,1,n){
		ans[i]=1ll*ans[i]*qpow(2,m)%mod;
		ans[i]=(ans[i]-min(i,n-i+1)+mod)%mod;
//		printf("ans[%d]=%d\n",i,ans[i]);
		ans[i]=1ll*ans[i]*qpow(qpow(2,m)-1,mod-2)%mod;
	}
	FOR(i,1,n) res=(res+1ll*w[i]*ans[i])%mod;
	printf("%d\n",res);
}