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
typedef long double K;
typedef vector<int> VI;

const int INF = 1000000000;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, res;
int X[200010];
int W[200010];
int R[200010];

struct event {
	int i, type, x;
};

bool cmp(event a, event b){
	if(a.x != b.x) return a.x < b.x;
	return a.type < b.type;
}

vector<event> E;

int main(){
	scanf("%d", &n);
	event e;
	FWD(i,0,n){
		scanf("%d %d", &X[i], &W[i]);
		e.i = i;
		e.type = 1;
		e.x = X[i] - W[i];
		E.push_back(e);
		e.type = -1;
		e.x = X[i] + W[i];
		E.push_back(e);
	}
	sort(ALL(E), cmp);
	FWD(i,0,SIZE(E)){
		e = E[i];
//		printf("event %d %d %d\n", e.i, e.type, e.x);
		if(e.type == -1) res = max(res, R[e.i]);
		else R[e.i] = res + 1;
	}
	printf("%d\n", res);
	return 0;
}