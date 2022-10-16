#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=1000000007;
#define MP make_pair
#define PB push_back
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
int n,m,f[maxn],b[maxn],lst,ans,l[maxn],stk[maxn],tp;
bool in[maxn];
struct seg{
	int l,r,id;
	bool operator<(const seg &s)const{return r<s.r;}
}s[maxn];
inline void update(int p,int v){
	for(int i=p;i<=2*n;i+=i&-i) b[i]=(b[i]+v)%mod;
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s=(s+b[i])%mod;
	return s;
}
int main(){
	n=read();
	FOR(i,1,n){
		int l=read(),r=read();
		s[i]=(seg){l,r,i};
	}
	m=read();
	while(m--) in[read()]=true;
	sort(s+1,s+n+1);
	FOR(i,1,n){
		f[i]=(1+query(s[i].r)-query(s[i].l)+mod)%mod;
		update(s[i].l,f[i]);
	}
	ROF(i,n,1) if(in[s[i].id]){
		if(lst && !(s[i].l>s[lst].l && s[i].r<s[lst].r)) continue;
		stk[++tp]=i;
		lst=i;
	}
	MEM(b,0);
	int cur=1;
	while(tp){
		int i=stk[tp--];
		ans=(ans+1+(query(s[i].r)-query(s[i].l)+mod)%mod)%mod;
		while(cur<=i-1) update(s[cur].l,f[cur]),ans=(ans+f[cur++])%mod;
	}
	printf("%d\n",ans);
}