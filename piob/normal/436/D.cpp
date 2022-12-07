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

const int INF = 1000000010;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, m, res;
int M[100010];
int F[100010];
int L[100010];
int C[2010];

int A[100010];
int B[100010];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,1,n+1) scanf("%d", &M[i]);
	sort(M+1, M+n+1);
	F[1] = 1;
	FWD(i,2,n+1) if(M[i-1]+1 == M[i]) F[i] = F[i-1]; else F[i] = i;
	L[n] = n;
	BCK(i,n-1,0) if(M[i+1]-1 == M[i]) L[i] = L[i+1]; else L[i] = i;
	C[0] = -1;
	FWD(i,1,m+1) scanf("%d", &C[i]);
	sort(C+1, C+m+1);
	C[m+1] = 1000000;
	m += 2;
	FWD(i,1,n+1){
		int j = 0;
		while(j < m && C[j+1] <= M[i]) ++j;
		A[i] = max(A[i], B[F[i]-1]);
		BCK(k,j,-1)
			if(i-(M[i]-C[k]) >= 1)
				A[i] = max(A[i], j-k+1 + B[F[i-(M[i]-C[k])]-1]);
			else
				break;
		B[i] = max(B[i], A[i]);
		B[i] = max(B[i], B[i-1]);
		FWD(k,j+1,m)
			if(i+C[k]-M[i] <= n)
				B[i + C[k]-M[i]] = max(B[L[i+C[k]-M[i]]], k-j + A[i]);
			else
				break;
		res = max(res, B[i]);
	}
	printf("%d\n", res);
	return 0;
}