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

const int MAX_N=210;
int F[MAX_N],H[MAX_N];
bool Cycle[MAX_N];
int Was[MAX_N];
vi S;
vector<LL> List;

void DFS(int v){
	Was[v]=1;
	S.pb(v);
	if(Was[F[v]]==1){
		Cycle[F[v]]=1;
		int cnt=1;
		for(int i=(int)S.size()-1;i>=0 && S[i]!=F[v];--i)
			Cycle[S[i]]=1, ++cnt;
		List.pb(cnt);
	}else if(!Was[F[v]])
		DFS(F[v]);
	Was[v]=2;
	S.pop_back();
}

int DFS2(int v){
	if(Cycle[v])
		return 0;
	else if(H[v]==0)
		return H[v]=1+DFS2(F[v]);
	else
		return H[v];
}

int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N;
	scanf("%d",&N);
	forn(i,N)
		scanf("%d",&F[i]), --F[i];
	forn(i,N)
		if(!Was[i])
			DFS(i);
	int m=1;
	forn(i,N)
		if(!Cycle[i])
			m=max(m,DFS2(i));
	LL P=1;
	forit(a,List)
		P=P*(*a)/__gcd(P,*a);
	printf(lld"\n",(m+P-1)/P*P);

	return 0;
}