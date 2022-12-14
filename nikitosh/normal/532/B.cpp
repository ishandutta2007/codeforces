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
const LL INF=1e18;
LL D[MAX_N][2], F[MAX_N][2];
int A[MAX_N];
vi Edges[MAX_N];

void DFS(int v){
	int L=Edges[v].size();
	F[0][0]=0, F[0][1]=-INF;
	forn(i,L){
		int u=Edges[v][i];
		DFS(u);
	}
	forn(i,L){
		int u=Edges[v][i];
		forn(k,2)
			F[i+1][k]=max(F[i][k]+D[u][0],F[i][!k]+D[u][1]);
	}
	D[v][0]=F[L][0];
	D[v][1]=max(F[L][1],A[v]+F[L][0]);
}

int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N;
	scanf("%d",&N);
	forn(i,N){
		int p;
		scanf("%d%d",&p,&A[i]);
		if(p!=-1)
			Edges[p-1].pb(i);
	}
	
	DFS(0);
	printf(lld"\n",max(D[0][0],D[0][1]));

	return 0;
}