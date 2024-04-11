#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 200+5;
int n;
LL t1,t2;
int _a[MAXN];

inline P query(int x){
	printf("+ %d\n",x);std::fflush(stdout);
	LL q1,q2;scanf("%lld%lld",&q1,&q2); 
//	_a[x]++;LL q1=0,q2=0;FOR(i,1,n) q1 += _a[i]*(_a[i]-1)/2;
//	FOR(i,1,n-2) q2 += _a[i]*_a[i+1]*_a[i+2];
	P res = MP(q1-t1,q2-t2);
	t1 = q1;t2 = q2;return res;
}

int d[MAXN];

inline int get(int x){
	int n = std::sqrt(8.0*x+1);n++;n >>= 1;
	return n+1; 
}

int a[MAXN];

int main(){
	scanf("%d%lld%lld",&n,&t1,&t2);
//	FOR(i,1,n) scanf("%d",_a+i);
	ROF(i,n-1,3) d[i] = query(i).se;
	int x1 = query(1).se; // x1 = a[2](a[3]+1)
	int x2 = query(2).se; // x2 = (a[1]+1)(a[3]+1)+(a[3]+1)(a[4]+1)
	int x3;std::tie(a[1],x3) = query(1);
	// x3 = (a[2]+1)(a[3]+1)
	a[1] = get(a[1]);a[1] -= 2;
	a[3] = x3-x1-1;
	a[2] = x1/(a[3]+1);
	a[4] = (x2-(a[1]+1)*(a[3]+1))/(a[3]+1)-(4!=n);
	FOR(i,3,n-2){
		a[i+2] = (d[i]-a[i-2]*a[i-1]-a[i-1]*(a[i+1]+1))/(a[i+1]+1)-(i+2!=n);
	}
	printf("! ");FOR(i,1,n) printf("%d ",a[i]);puts("");std::fflush(stdout);
	return 0;
}