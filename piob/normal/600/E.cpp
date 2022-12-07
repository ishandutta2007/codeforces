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

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int mod = 1000000007;
const K eps = 1e-15;

struct mm {
	map<int, int> cnt;
	LL s; int v;
	mm(){
		s = 0;
		v = -1;
	}
	void add(int c, int t){
		cnt[c] += t;
		if(cnt[c] > v){
			s = c;
			v = cnt[c];
		}else if(cnt[c] == v)
			s += c;
	}
};

void swp(mm &a, mm &b){
	swap(a.cnt, b.cnt);
	swap(a.s, b.s);
	swap(a.v, b.v);
}

int n;
bool vis[100010];
vector<int> out[100010];
int col[100010];
mm res[100010];

void dfs(int u){
	vis[u] = 1;
	res[u].add(col[u], 1);
	for(int v : out[u]) if(!vis[v]){
		dfs(v);
		LL ss = res[v].s;
		if(res[u].cnt.size() < res[v].cnt.size())
			swp(res[u], res[v]);
		for(auto ct : res[v].cnt)
			res[u].add(ct.st, ct.nd);
		res[v].cnt.clear();
		res[v].s = ss;
	}
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1) scanf("%d", &col[i]);
	FWD(i,1,n){
		int a, b;
		scanf("%d %d", &a, &b);
		out[a].push_back(b);
		out[b].push_back(a);
	}
	dfs(1);
	FWD(i,1,n+1) printf("%I64d ", res[i].s);
	printf("\n");
	return 0;
}