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

int n;
vector<int> children[100010];
int siz[100010];
long double et[100010];

int main(){
	scanf("%d", &n);
	FWD(i,2,n+1){
		int p;
		scanf("%d", &p);
		children[p].push_back(i);
	}
	BCK(u,n,0){
		siz[u] = 1;
		for(int v : children[u])
			siz[u] += siz[v];
	}
	et[1] = 1;
	FWD(u,1,n+1){
		for(int v : children[u])
			et[v] = et[u] + 1 + (siz[u] - siz[v] - 1.0) / 2;
		printf("%.7Lf ", et[u]);
	}
	printf("\n");
	return 0;
}