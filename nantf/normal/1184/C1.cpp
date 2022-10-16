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
		while(!isdigit(c)){ f^=(c=='-'); c=getchar(); }
		for(;isdigit(c);c=getchar()) ans=ans*10+c-'0'; return f?ans:-ans;
	}
	const int mod = 998244353;
	inline void inc(int &x,const int &y){ x+=y; if(x>=mod) x-=mod; }
	inline int ksm(int x,LL y){ int res=1; for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod; return res;}
	inline int gcd(int x,int y){ if(x<y) swap(x,y); return y?gcd(y,x%y):x; }
	#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
}
using namespace my_std;

struct PoXoY{
	int x,y;
	inline bool operator <(const PoXoY &A)const{
		return x < A.x;
	}
}a[55];
int bx[55],by[55],lx[5],ly[5],n;

inline bool cctv(int x){
	if(a[x].x != lx[1] && a[x].x != lx[2] && a[x].y != ly[1] && a[x].y != ly[2]) return 0;
	if((a[x].x > lx[2] || a[x].x < lx[1]) || (a[x].y > max(ly[1],ly[2]) || a[x].y < min(ly[1],ly[2]))) return 0;
	return 1;
}

inline bool check(int x){
	int k = -1 , miny = 99 , ans = 0;
	FOR(i,2,n){
		if(i == x) continue;
//		maxy = max(maxy , a[i].y);
		miny = min(miny , a[i].y);
		if(a[i].x != lx[1] && a[i].x != lx[2]){
			ly[1] = a[i].y;
			if(miny < ly[1]) ly[2] = ly[1] - lx[2] + lx[1];
			else ly[2] = ly[1] + lx[2] - lx[1];
			k = i + 1;
			break;
		}
	}
//	printf("LY : %d %d\n",ly[1],ly[2]);
	FOR(i,k,n){
		if(i == x) continue;
		if(a[i].x != lx[1] && !cctv(i)) ans++;
	}
//	printf("Check : a[%d] = (%d,%d)  ans : %d\n",x,a[x].x,a[x].y,ans);
	if(!ans && !cctv(x)) return 1;
	return 0;
}

int main(){
	n = read();
	FOR(i,1,n << 2 | 1) a[i].x = read() , a[i].y = read();
	sort(a + 1,a + (n << 2 | 1) + 1);
	n = n << 2 | 1;
	lx[1] = a[1].x == a[2].x ? a[1].x : a[2].x ;
	lx[2] = a[n].x == a[n-1].x ? a[n].x : a[n-1].x ;
//	FOR(i,1,n) printf("(%d %d)\n",a[i].x,a[i].y);
//	printf("LX : %d %d\n",lx[1],lx[2]);
	FOR(i,1,n){
		if(check(i)){ printf("%d %d\n",a[i].x,a[i].y); return 0; }
	}
	return 0;
}