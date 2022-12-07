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
const int INF = 1000000010;

int n, q;
int A[2000010];
LL S[2000010];
int D[2000010];
int W[2000010];

LL get_sum(int a, int b){
	return S[b] - S[a-1];
}

int cost, destination;

void go(int a, int b){
	if(a >= b){
		cost = 0;
		destination = a;
		return;
	}
	go(W[a], b);
	cost += D[a];
	W[a] = destination;
	D[a] = cost;
}

int main(){
	scanf("%d %d", &n, &q);
	FWD(i,1,n+1) scanf("%d", &A[i]);
	FWD(i,1,n+1) A[n+i] = A[i];
	FWD(i,1,2*n+1) S[i] = S[i-1] + A[i];
	FWD(r,0,q){
		int b;
		scanf("%I64d", &b);
		int res = INF;
		if(get_sum(1,n) <= b){
			res = 1;
		}else{
			int lim = 2*n+1;
			BCK(i,2*n,0){
				while(get_sum(i,lim-1) > b) --lim;
				D[i] = 1;
				W[i] = lim;
			}
			FWD(i,1,n+1){
				go(i, i+n);
				res = min(res, cost);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}