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

int n;
vector<int> child[200010];
int size[200010];
int res[200010];

void dfs(int u, bool h){
	size[u] = 0;
	if(SIZE(child[u]) == 0){
		size[u] = 1;
		res[u] = 1;
		return;
	}
	for(int v : child[u]){
		dfs(v, !h);
		size[u] += size[v];
	}
	res[u] = 1;
	if(!h){
		for(int v : child[u]) res[u] = max(res[u], res[v] + size[u] - size[v]);
	}else{
		int smaller = 0;
		for(int v : child[u]) smaller += res[v] - 1;
		res[u] = smaller + 1;
	}
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n){
		int a, b;
		scanf("%d %d", &a, &b);
		child[a].push_back(b);
	}
	dfs(1, 0);
	printf("%d ", res[1]);
	dfs(1, 1);
	printf("%d\n", size[1]+1-res[1]);
	return 0;
}