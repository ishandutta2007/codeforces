#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define reg register
	#define Rint register int
	#define FOR(i,a,b) for(register int i=(a);i<=(b);++i)
	#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
	#define FORit(templ,arr,i,a,b) for(register templ *i=(arr)+(a);i!=(arr)+(b)+1;++i)
	#define ROFit(templ,arr,i,a,b) for(register templ *i=(arr)+(a);i!=(arr)+(b)-1;--i)
	#define GO(x,p,e,i,v) for(register int i=p[x].head,v;i;i=e[i].link)
	#define MEM(x,v) memset(x,v,sizeof(x))
	#define fir first
	#define sec second
	#define pq priority_queue
	#define PII pair<int,int>
	#define MP make_pair
	typedef long long LL;
	typedef double DB;
	inline int read(){
		int ans=0,f=1;char c=getchar();
		while(c>'9'||c<'0'){ f^=(c=='-'); c=getchar(); }
		for(;c<='9'&&c>='0';c=getchar()) ans=ans*10+c-'0'; return f?ans:-ans;
	}
	const int mod = 998244353,maxn=200020;
	inline void inc(int &x,const int &y){ x+=y; if(x>=mod) x-=mod; }
	inline int ksm(int x,LL y){ int res=1; for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod; return res;}
	inline int gcd(int x,int y){ if(x<y) swap(x,y); return y?gcd(y,x%y):x; }
	#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
}
using namespace my_std;

struct Edge{
	int link,to;
};
struct Vertice{
	int head,wgh;
};
int n,ans,cnt[maxn];
char s[maxn];
bool check(int x){
	FOR(i,0,x-1){
		int sum=0;
		for(int j=i,f=0;!f || j!=i;j=(j+x)%n,f=1) sum+=s[j]-'0';
		if(sum&1) return false;
	}
	return true;
}
int main(){
	n=read();
	scanf("%s",s);
	FOR(i,1,n) cnt[gcd(i,n)]++;
	for(int i=1;i*i<=n;i++) if(n%i==0){
		if(check(i)) ans+=cnt[i];
		if(i*i!=n && check(n/i)) ans+=cnt[n/i];
	}
	printf("%d\n",ans);
	return 0;
}