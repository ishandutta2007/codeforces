    #include<bits/stdc++.h>
    namespace my_std{
    	using namespace std;
    	#define reg register
    	#define Rint register int
    	#define FOR(i,a,b) for(register int i=(a),ed_##i=(b);i<=ed_##i;++i)
    	#define ROF(i,a,b) for(register int i=(a),ed_##i=(b);i>=ed_##i;--i)
    	#define FORit(templ,arr,i,a,b) for(register templ *i=(arr)+(a),*ed_##i=(arr)+(b)+1;i!=ed_##i;++i)
    	#define ROFit(templ,arr,i,a,b) for(register templ *i=(arr)+(a),*ed_##i=(arr)+(b)-1;i!=ed_##i;--i)
    	#define GO(x,p,e,i,v) for(register int i=p[x].head,v;i;i=e[i].link)
    	#define MEM(x,v) memset(x,v,sizeof(x))
    	#define fir first
    	#define sec second
    	#define pq priority_queue
    	#define MP make_pair
    	typedef long long LL;
    	typedef double DB;
    	typedef pair<int,int> PII;
    	#define Templ(T) template<typename T>
    	inline int read(){
    		int ans=0,f=1;char c=getchar();
    		while(!isdigit(c)){ f^=(c=='-'); c=getchar(); }
    		for(;isdigit(c);c=getchar()) ans=ans*10+c-'0'; return f?ans:-ans;
    	}
    	Templ(_Tp) inline int chkmin(_Tp &x,_Tp y){ return x>y?x=y,1:0; }
    	Templ(_Tp) inline int chkmax(_Tp &x,_Tp y){ return x<y?x=y,1:0; }
    	#define using_mod
    	const int mod = 998244353 , N = 500010 , SN = 2666;
    	#ifdef using_mod
    	inline void inc(int &x,const int &y){ x+=y; if(x>=mod) x-=mod; }
    	inline int ksm(int x,LL y){ int res=1; for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod; return res;}
    	#endif
    	Templ(_Tp) inline _Tp gcd(_Tp x,_Tp y){ return y?gcd(y,x%y):x; }
    	#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
    	#define PBTXDY
    }
    using namespace my_std;
     
    inline char getC(){
    	reg char c = getchar(); while('A' > c || c > 'Z') c = getchar(); return c;
    }
    int n,m,blo;
    LL a[N] , ans[SN][SN];
     
    inline void update(int x,LL val){
    	a[x] += val;
    	FOR(i,1,blo) ans[i][x % i] += val;
    	return;
    }
     
    inline LL query(int p,int x){
    	if(p <= blo) return ans[p][x % p];
    	reg LL res = 0;
    	for(Rint i = x % p;i <= n;i += p) res += a[i];
    	return res;
    }
     
    int main(){
    //	FILE("LuoguP3396");
    	n = 500000 , m = read();
    	blo = ceil(pow(n,0.45));
    //	FOR(i,1,n){
    //		a[i] = read();
    //		FOR(j,1,blo) ans[j][i % j] += a[i];
    //	}
    	Rint x,y,sta;
    	FOR(qry,1,m){
    		sta = read() - 1 , x = read() , y = read();
    		sta ? void(printf("%lld\n",query(x,y))) : update(x,(LL)y) ;
    	}
    	return 0;
    }