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

struct ev{
	int t, data, type;
	ev(int t=0,int data=0,int type=0):t(t),data(data),type(type){}
	inline bool operator<(const ev &B) const{
		return t<B.t || (t==B.t && type<B.type);
	}
};

vector<ev> EvX, EvY;
const int ST_SZ=1<<17, ST_SZ2=2*ST_SZ, MAX_Q=2e5+10;
#define y1 usdhfsdfksdf
int x1[MAX_Q], y1[MAX_Q], x2[MAX_Q], y2[MAX_Q];
int ST[ST_SZ2];
bool Good[MAX_Q];
const int INF=1e9;

inline int Get(int L,int R){
	int S=INF;
	for(L+=ST_SZ,R+=ST_SZ;L<R;L>>=1, R>>=1){
		if(L&1) S=min(S,ST[L++]);
		if(R&1) S=min(S,ST[--R]);
	}
	return S;
}

inline void Set(int k,int x){
	ST[k+=ST_SZ]=x;
	for(k>>=1;k>0;k>>=1)
		ST[k]=min(ST[k*2],ST[k*2+1]);
}

int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N,M,K,Q;
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	forn(i,K){
		int x,y;
		scanf("%d%d",&x,&y);
		EvX.pb(ev(x,y,0));
		EvY.pb(ev(y,x,0));
	}
	forn(i,Q){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		EvX.pb(ev(x2[i],i,1));
		EvY.pb(ev(y2[i],i,1));
	}
	
	sort(all(EvX));
	forit(e,EvX){
		if(e->type==0)
			Set(e->data,e->t);
		else if(Get(y1[e->data],y2[e->data]+1)>=x1[e->data])
			Good[e->data]=1;
	}

	forn(i,ST_SZ2)
		ST[i]=0;
		
	sort(all(EvY));
	forit(e,EvY){
		if(e->type==0)
			Set(e->data,e->t);
		else if(Get(x1[e->data],x2[e->data]+1)>=y1[e->data])
			Good[e->data]=1;
	}
		
	forn(i,Q)
		puts(Good[i]?"YES":"NO");

	return 0;
}