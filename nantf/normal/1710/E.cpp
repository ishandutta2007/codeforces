#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,m,a[maxn],b[maxn],x,y,c[maxn],r[maxn];
ll c1[maxn],c2[maxn];
bool check(int w){
	if(a[x]+b[y]<w) return false;
	ll s1=0,s2=0;
	int j=m;
//	printf("w=%d\n",w);
	FOR(i,1,n){
		while(j && a[i]+b[j]>=w) j--;
		r[i]=m-j;
	}
	j=n;
	FOR(i,1,m){
		while(j && a[j]+b[i]>=w) j--;
		c[i]=n-j;
	}
	FOR(i,0,n) c1[i]=c2[i]=0;
	FOR(i,1,m) c1[c[i]]++,c2[c[i]]+=c[i];
	FOR(i,1,n) c1[i]+=c1[i-1],c2[i]+=c2[i-1];
	ll s=0;
	FOR(i,1,n){
		s-=r[i];
		s1=max(s1,s+i*c1[i]-c2[i]);
	}
	r[x]--;c[y]--;
	FOR(i,0,n) c1[i]=c2[i]=0;
	FOR(i,1,m) c1[c[i]]++,c2[c[i]]+=c[i];
	FOR(i,1,n) c1[i]+=c1[i-1],c2[i]+=c2[i-1];
	s=0;
	FOR(i,1,n){
		s-=r[i];
		s2=max(s2,s+i*c1[i]-c2[i]-(i>=x && i-1>=c[y]));
	}
	FOR(i,1,n){
		if(i==x) continue;
		s-=r[i];
		int ii=i-(i>=x);
		s2=max(s2,s+ii*c1[ii]-c2[ii]);
	}
//	printf("%lld and %lld\n",s1,s2);
	return s1==s2;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,m) b[i]=read();
	int aa=a[1],bb=b[1];
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	x=lower_bound(a+1,a+n+1,aa)-a;
	y=lower_bound(b+1,b+m+1,bb)-b;
//	printf("x=%d,y=%d\n",x,y);
	int l=2,r=1e9;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}