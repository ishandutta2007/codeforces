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
	const int mod = 998244353,maxn=255;
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
int n,m,k,t,len,tp[maxn];
int main(){
	n=read();k=read();m=read();t=read();
	len=n;
	tp[k]=1;
	while(t--){
		int op=read(),x=read();
		if(op){
			len++;
			ROF(i,len,x+1) tp[i]=tp[i-1];
			tp[x]=0;
		}
		else{
			bool lft=false;
			FOR(i,1,x) if(tp[i]){lft=true;break;}
			if(lft){
				FOR(i,x+1,len) tp[i]=0;
				len=x;
			}
			else{
				FOR(i,1,len-x) tp[i]=tp[i+x];
				FOR(i,len-x+1,len) tp[i]=0;
				len-=x;
			}
		}
		printf("%d ",len);
		FOR(i,1,len) if(tp[i]){printf("%d\n",i);break;}
	}
	return 0;
}