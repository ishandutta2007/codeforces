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

const double pi = acos(-1.0);

double x[1<<20], y[1<<20];
int alpha[1<<20];

void rotate_vector(int i, int r) {
	r = r % 360;
	double a = atan2(y[i], x[i]);
	double len = sqrt(x[i]*x[i] + y[i]*y[i]);
	a += r / 180.0 * pi;
	x[i] = len * cos(a);
	y[i] = len * sin(a);
}

void extend_vector(int i, int l) {
	double len = sqrt(x[i]*x[i] + y[i]*y[i]);
	x[i] = x[i] * (l + len) / len;
	y[i] = y[i] * (l + len) / len;
}

void pushup(int t) {
	x[t] = x[lson(t)] + x[rson(t)];
	y[t] = y[lson(t)] + y[rson(t)];
}

void pushdown(int t) {
	if(alpha[t]) {
		alpha[lson(t)] += alpha[t];
		alpha[rson(t)] += alpha[t];
		rotate_vector(lson(t), alpha[t]);
		rotate_vector(rson(t), alpha[t]);
		alpha[t] = 0;
	}
}

void rotate(int t, int L, int R, int l, int r, int angle) {
	l = max(l,L);
	r = min(r,R);
	if(l > r) return ;
	if(L == l && r == R) {
		rotate_vector(t, angle);
		alpha[t] += angle;
		return ;
	}
	pushdown(t);
	int M = (L+R)>>1;
	rotate(lson(t), L, M, l, r, angle);
	rotate(rson(t), M+1, R, l, r, angle);
	pushup(t);
}

void extend(int t, int L, int R, int l, int len) {
	if(L == R) {
		extend_vector(t, len);
		return ;
	}
	pushdown(t);
	int M = (L+R)>>1;
	if(l <= M) extend(lson(t), L, M, l, len);
	else extend(rson(t), M+1, R, l, len);
	pushup(t);
}

int N = 1;
void init(int n) {
	N = 1;
	while(N <= n) N*=2;
	REP(i,N) {
		x[N+i] = i < n ? 1.0 : 0.0;
		y[N+i] = 0.0;
		alpha[N+i] = 0;
	}
	DEP(i,N-1,0) {
		pushup(i);
	}
}

int main()
{
#ifdef LOCAL
	   //freopen("x.in","r",stdin);
	   //freopen("x.out","w",stdout);
#endif
	int n, m;
	scanf("%d%d",&n,&m);
	init(n);
	REP(i,m) {
		int _x, _y, _z;
		scanf("%d%d%d",&_x,&_y,&_z);
		if(_x == 1) {
			_y--;
			extend(1,0,N-1,_y,_z);
		}else{
			_y--;
			rotate(1,0,N-1,_y,N-1,360-_z);
		}
		printf("%.12lf %.12lf\n", x[1], y[1]);
	}
	return 0;
}