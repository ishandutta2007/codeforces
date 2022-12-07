#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef long double K;
typedef vector<int> VI;

const int INF = 1000000001;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

struct line {
	LL a, b;
	mutable LL x0, x1;
	
	LL val(LL x) const { return a*x + b; } // UWAGA NA OVERFLOW
	
	bool above(const line &k) {
		return val(k.x0) >= k.val(k.x0) && val(k.x1-1) >= k.val(k.x1-1);
	}
	
	bool operator<(const line &rhs) const {
		return a != rhs.a ? a < rhs.a : b < rhs.b;
	}
};

inline LL ceil(LL a, LL b) {  if((a^b) > 0) a += b + 2*(b<0)-1; return a/b; }

void add_line(vector<line> &lines, LL a, LL b) { // y = a*x + b
	line k({a, b, -INF, INF});
	vector<line>::iterator s, t;
	s = lines.end();
	while(s != lines.begin()){
		if(!k.above(*--s)){
			s++;
			break;
		}else{
			lines.pop_back();
			s = lines.end();
		}
	}
	lines.push_back(k);
	s = --lines.end();
	t = lines.end();
	if(s != lines.begin()){
		t = s--;
		s->x1 = t->x0 = ceil(s->b - t->b, t->a - s->a);
	}
	if(s->x0 == s->x1) lines.erase(s);
}

PLI get_max(vector<line>::iterator &it, LL x) {
	while(x >= it->x1) ++it;
	return PLI(it->val(x), it->a);
}

const int B = 320;
const int MAXN = B*B;
int data[MAXN];
void add(int i, int v){ for (; i < MAXN; i |= i + 1) data[i] += v; }
int sum(int i){ int s=0; while(i>=0) { s+=data[i]; i=(i&(i+1))-1; } return s; }
int sum(int a, int b){ return sum(b) - sum(a-1); }

int X[B];
vector<line> lines[B];
vector<line>::iterator it[B];

void dorzuc(int a){
	//printf("dorzucam %d\n", a);
	int v = 0;
	add(a, 1);
	while(v*B + B <= a){
		++X[v];
		++v;
	}
	X[v] = 0;
	lines[v].clear();
	FWD(i,0,B) add_line(lines[v], v*B+i, (LL)sum(v*B+i, MAXN-1)*(v*B+i));
	it[v] = lines[v].begin();
}

void wypisz(LL bonus){
	PLI best = PII(0, 0);
	FWD(v,0,B){
		PLI cur = get_max(it[v], X[v]);
		best = max(best, cur);
	}
#ifdef LOCAL_JUDGE
	printf("%lld %d\n", best.st+bonus, best.nd);
#else
	printf("%I64d %d\n", best.st+bonus, best.nd);
#endif
}

int n, w, k;
vector<PII> V;

int main(){
	scanf("%d %d", &n, &w);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		V.push_back(PII(b, a));
		k = max(k, b);
	}
	sort(ALL(V));
	FWD(v,0,B){
		FWD(i,0,B)
			add_line(lines[v], v*B+i, 0);
		it[v] = lines[v].begin();
	}
	int i = 0;
	FWD(c,0,k+2){
		while(i < SIZE(V) && V[i].st < c){
			dorzuc(V[i].nd);
			++i;
		}
		wypisz((LL)(n-i)*c*w);
	}
	return 0;
}