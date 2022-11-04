#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int x[100000], y[100000];
int id[100000];

int cmp(int a, int b) {
	return x[a] == x[b] ? y[a] < y[b] : x[a] < x[b];
}

PII operator-(PII a, PII b) {
	return MP(a.X-b.X, a.Y-b.Y);
}

ll operator^(PII a, PII b) {
	return 1LL*a.Y*b.X-1LL*a.X*b.Y;
}

ll area(PII a, PII b, PII c) {
	return (b-a)^(c-a);
}

int main()
{
#ifdef LOCAL
	   //freopen("x.in","r",stdin);
	   //freopen("x.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	REP(i,n) {
		cin>>x[i]>>y[i];
		id[i] = i;
	}
	sort(id, id+n, cmp);
	PII p0 = MP(x[id[0]], y[id[0]]),
		p1 = MP(x[id[1]], y[id[1]]);
	for(int i = 2; i < n; i++) {
		PII p2 = MP(x[id[i]], y[id[i]]);
		if(area(p0, p1, p2) != 0) {
			cout<<id[0]+1<<' '<<id[1]+1<<' '<<id[i]+1<<endl;
			return 0;
		}
	}
	return 0;
}