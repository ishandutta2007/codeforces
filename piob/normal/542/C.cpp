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
int F[210];
int V[210];
int D[210];
bool C[210];
LL g;

int dfs(int u){
	if(D[u] != -1) return D[u];
	if(C[u]){
		D[u] = 0;
		return 0;
	}
	return D[u] = dfs(F[u]) + 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	FWD(i,1,n+1) scanf("%d", &F[i]);
	g = 1;
	FWD(i,1,n+1){
		FWD(j,1,n+1) V[j] = 0;
		int u = i;
		int s = 0;
		do{
			V[u] = 1;
			u = F[u];
			++s;
		}while(!V[u]);
		C[i] = (u == i);
		if(C[i]) g = g / gcd(g, (LL)s) * s;
	}
	FWD(i,1,n+1) D[i] = -1;
	FWD(i,1,n+1) if(D[i] == -1) dfs(i);
	LL r = g;
	FWD(i,1,n+1) while(r < D[i]) r += g;
	cout << r << endl;
	return 0;
}