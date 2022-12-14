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
const int MAX_N=105;
int Z[MAX_N][MAX_N];

pii A[MAX_N][MAX_N];

int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N,M,Q;
	scanf("%d%d%d",&N,&M,&Q);
	forn(i,N)
		forn(j,M)
			A[i][j]=mp(i,j);
	forn(q,Q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int r;
			scanf("%d",&r), --r;
			rotate(A[r],A[r]+1,A[r]+M);
		}else if(t==2){
			int c;
			scanf("%d",&c), --c;
			pii z=A[0][c];
			forn(i,N-1)
				A[i][c]=A[i+1][c];
			A[N-1][c]=z;
		}else if(t==3){
			int r,c,x;
			scanf("%d%d%d",&r,&c,&x), --r, --c;
			pii &p=A[r][c];
			int a=p.fst, b=p.snd;
			Z[a][b]=x;
		}
	}
	
	forn(i,N){
		forn(j,M)
			printf("%d ",Z[i][j]);
		puts("");
	}

	return 0;
}