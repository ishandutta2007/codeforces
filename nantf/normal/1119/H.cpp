#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=133333,mod=998244353,inv2=499122177;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,k,x,y,z,lim,tot,a[maxn],b[maxn],c[maxn],d[maxn];
void fwt(int *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1){
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=x+y;
				a[i+j+k]=x-y;
			}
}
void ifwt(int *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1){
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=1ll*(x+y)*inv2%mod;
				a[i+j+k]=1ll*(x-y+mod)*inv2%mod;
			}
}
int main(){
	n=read();k=read();
	lim=1<<k;
	x=read();y=read();z=read();
	FOR(i,1,n){
		int a=read(),b=read(),c=read();
		tot^=a;b^=a;c^=a;
		::a[b]++;::b[c]++;::c[b^c]++;
	}
	fwt(a);fwt(b);fwt(c);
	int tmp1=((x+y)%mod+z)%mod;
	int tmp2=((x+y)%mod-z+mod)%mod;
	int tmp3=((x-y+mod)%mod+z)%mod;
	int tmp4=((x-y+mod)%mod-z+mod)%mod;
	FOR(i,0,lim-1){
		int p=(n+a[i])/2,q=(n+b[i])/2,r=(n-c[i])/2;
		int s=(p+q+r)/2;
		int a=s-r,b=s-q,c=s-p,d=n-s;
		::d[i]=1ll*qpow(tmp1,a)*qpow(tmp2,b)%mod*qpow(tmp3,c)%mod*qpow(tmp4,d)%mod;
	}
	ifwt(d);
	FOR(i,0,lim-1) printf("%d ",d[i^tot]);
}