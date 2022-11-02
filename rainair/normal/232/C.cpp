#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 80+5;
LL f[MAXN];
// std::unordered_map<LL,LL> S1[MAXN],Sn[MAXN];
// gp_hash_table<LL,LL> S1[MAXN],Sn[MAXN];

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

LL d[2][2][MAXN];
//  1/n

inline LL work(LL u,LL v,int n){
	if(u == v) return 0;
	if(u+1 == v) return 1;
	// printf("%lld %lld\n",u,v);
	// assert(n >= 2);
	LL ls = f[n-1];
	LL res = 0;
	if(u > ls && v > ls) res = work(u-ls,v-ls,n-2);
	// else if(u <= ls && v <= ls) res = std::min({work(u,v,n-1),work(1,u,n-1)+work(v,ls,n-1)+2,work(1,v,n-1)+work(u,ls,n-1)+2});
	else if(u <= ls && v <= ls) res = std::min({work(u,v,n-1),d[0][0][n-1]+d[1][1][n-1]+2,d[0][1][n-1]+d[1][0][n-1]+2});
	// else res = std::min(work(1,u,n-1),work(u,ls,n-1))+work(1,v-ls,n-2)+1;
	else res = std::min(d[0][0][n-1],d[0][1][n-1])+d[1][0][n-2]+1;
	return res;
}
/*
v->1v->f[n]
u,v O(n)
*/

LL t[MAXN];// 

inline void prework(LL v,int n,LL t1[],LL tn[]){
	if(n == 0){
		t1[n] = tn[n] = 0;return;
	}
	if(n == 1){
		t1[n] = (v!=1);tn[n] = (v!=2);return;
	}
	LL ls = f[n-1];
	if(v <= ls){
		prework(v,n-1,t1,tn);
		t1[n] = std::min(t1[n-1],tn[n-1]+2);
		tn[n] = std::min(tn[n-1],t1[n-1])+1+t[n-2];
	}
	else{
		prework(v-ls,n-2,t1,tn);
		t1[n] = t1[n-2]+1;
		tn[n] = tn[n-2];
	}
}

int main(){
	f[0] = 1;f[1] = 2;t[0] = 0;t[1] = 1;
	FOR(i,2,90) f[i] = f[i-1]+f[i-2],t[i] = t[i-2]+1;
	int q,n;read(q);read(n);n = std::min(n,80);
	FOR(i,1,q){
		LL u,v;read(u);read(v);if(u > v) std::swap(u,v);
		prework(u,n,d[0][0],d[0][1]);
		prework(v,n,d[1][0],d[1][1]);
		printf("%lld\n",work(u,v,n));
	}
	return 0;
}