#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<deque>
using namespace std;

#ifdef WIN32
	#define lld "%I64d"
	#define llu "%I64u"
#else
	#define lld "%lld"
	#define llu "%llu"
#endif

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<(b);++i)
#define forba(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define forit(i,A) for(__typeof((A).begin()) i=(A).begin();i!=(A).end();++i)
#define all(A) (A).begin(),(A).end()


const int MAX_N=2e5+100;
LL INF=1e18;
LL sum[MAX_N];
LD suminv[MAX_N], sumjtj[MAX_N];

const int MAX_K=55;
LD D[MAX_K][MAX_N];

int P[MAX_K][MAX_N], T[MAX_N];

inline LD S(int a,int b){
	return (sumjtj[b+1]-sumjtj[a])-sum[a]*(suminv[b+1]-suminv[a]);
}

inline void calc(int k, int a, int b, int l, int r){
	if(a>=b)
		return;

//		printf("%d %d %d\n",k,a,b);
	int cur=(a+b)/2;
	D[k][cur]=INF;
	for(int i=l;i<=min(r,cur-1);++i){
		LD z=D[k-1][i]+S(i+1, cur);
//		printf("cur=%d i=%d z=%f\n",cur,i,(double)z);
		if(z<D[k][cur])
			D[k][cur]=z, P[k][cur]=i;
	}
//	printf("D[%d][%d]=%.5f\n",k,cur,(double)D[k][cur]);
	if(a==b-1)
		return;
	calc(k, a, cur, l, P[k][cur]);
	calc(k, cur, b, P[k][cur], r);
}

int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N,K;
	scanf("%d%d",&N,&K);
	forn(i,N){
		scanf("%d",&T[i]), suminv[i+1]=suminv[i]+LD(1)/T[i];
		sum[i+1]=sum[i]+T[i];
		sumjtj[i+1]=sumjtj[i]+LD(sum[i+1])/T[i];
	}
	forn(i,N)
		D[1][i] = S(0, i);//, 	printf("D[%d][%d]=%.5f\n",1, i,(double)D[1][i]);
	for(int k=2;k<=K;++k)
		calc(k, 0, N, 0, N);
	printf("%.16f\n",(double)D[K][N-1]);

	return 0;
}