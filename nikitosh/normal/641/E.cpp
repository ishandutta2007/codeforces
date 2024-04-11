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


const int MAX_N=1e6+10;
vector<pair<int,pii> > V;
vector<int> F[MAX_N];
map<int,int> Map;
vector<int> List[MAX_N];

inline int Z(int a){
	return a&~(a-1);
}

inline void Add(int n,int k,int v){
//	printf("add %d %d %d\n",n,k,v);
	const int l=F[n].size();
	for(;k<l;k+=Z(k))
		F[n][k]+=v;
}

inline int Get(int n,int k){
//	printf("get %d %d ",n,k);
	int S=0;
	for(;k>0;k-=Z(k))
		S+=F[n][k];
//	printf("=%d\n",S);
	return S;
}

int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N;
	scanf("%d",&N);
	forn(i,N){
		int type,pos,x;
		scanf("%d%d%d",&type,&pos,&x);
		if(!Map.count(x)){
			int xx=Map.size();
			Map[x] = xx;
		}
		x=Map[x];
		V.pb(mp(x,mp(type,pos)));
		List[x].pb(V[i].snd.snd);
	}
	
	
	forit(i,Map){
		auto &l=List[i->snd];
		sort(all(l));
		F[i->snd].resize(l.size()+3);
	}
	
	forit(e,V){
		int x = e->fst, type = e->snd.fst, pos = lower_bound(all(List[x]), e->snd.snd)-List[x].begin()+1;
//		printf("type=%d\n",type);
		if(type==1)
			Add(x, pos, +1);
		else if(type==2)
			Add(x, pos, -1);
		else
			printf("%d\n",Get(x, pos));
	}

	return 0;
}