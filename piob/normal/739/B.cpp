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
long long S[200010];
int E[200010];
int R[200010];
int J[18][200010];
long long L[18][200010];
vector<int> out[200010];

int dfs(int u){
	int s = 0;
	for(int v : out[u])
		s += dfs(v);
	R[u] = s;
	return s + 1 - E[u];
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1)
		scanf("%lld", &S[i]);
	FWD(i,2,n+1){
		scanf("%d %lld", &J[0][i], &L[0][i]);
		out[J[0][i]].push_back(i);
	}
	L[0][1] = 1000000010;
	FWD(k,0,17)
		FWD(u,1,n+1){
			int v = J[k][u];
			J[k+1][u] = J[k][v]; 
			L[k+1][u] = L[k][u] + L[k][v];
		}
	FWD(u,1,n+1){
		int v = u;
		BCK(k,17,-1)
			if(S[u] >= L[k][v]){
				S[u] -= L[k][v];
				v = J[k][v];
			}
		++E[v];
	}
	dfs(1);
	FWD(i,1,n+1) printf("%d ", R[i]);
	printf("\n");
	return 0;
}