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

typedef long long int64;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

map<int64, int64> cost;

int64 lca(int64 u, int64 v){
	while(u!=v)
		if(u > v)
			u /= 2;
		else
			v /= 2;
	return u;
}

void add(int64 u, int64 v, int64 c){
	int64 w = lca(u,v);
	while(u!=w){
		cost[u] += c;
		u /= 2;
	}
	while(v!=w){
		cost[v] += c;
		v /= 2;
	}
}

int64 get(int64 u, int64 v){
	int64 w = lca(u,v);
	int64 r = 0;
	while(u!=w){
		r += cost[u];
		u /= 2;
	}
	while(v!=w){
		r += cost[v];
		v /= 2;
	}
	return r;
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int64 u, v, w;
			scanf("%lld %lld %lld", &u, &v, &w);
			add(u, v, w);
		}else{
			int64 u, v;
			scanf("%lld %lld", &u, &v);
			printf("%lld\n", get(u, v));
		}
	}
	return 0;
}