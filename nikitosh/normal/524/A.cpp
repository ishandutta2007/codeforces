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


vector<int> List,Z;
map<int,set<int> > G;
map<int, vector<int> > Edges;
int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int m,k,a,b;
	scanf("%d%d",&m,&k);
	forn(i,m)
		scanf("%d%d",&a,&b), List.pb(a), List.pb(b), Edges[a].pb(b), Edges[b].pb(a), G[a].insert(b), G[b].insert(a);
	sort(all(List)), List.resize(unique(all(List))-List.begin());

	forit(a,List){
		Z.clear();
		forit(b,List){
			if(*a!=*b && !G[*a].count(*b)){
				int x=0;
				forit(c,Edges[*a]){
					
					if(G[*c].count(*b))
						++x;
				}
				if(x*100>=k*(int)Edges[*a].size())
					Z.pb(*b);
			}
		}
			printf("%d: %d ",*a,Z.size());
			forit(t,Z)
				printf("%d ",*t);
			puts("");
}

	return 0;
}