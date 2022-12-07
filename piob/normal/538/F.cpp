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
int A[200010];
int R[200010];

vector<int> W;
vector<int> tree[2*256*1024+3];

int zlicz(int a, int c){
	return (int)(lower_bound(ALL(tree[a]), c) - tree[a].begin());
}

int d;

int cnt(int a, int b, int c){
	a += d;
	b += d;
	int r = 0;
	while(a < b){
		if(a&1){
			r += zlicz(a, c);
			++a;
		}
		if(!(b&1)){
			r += zlicz(b, c);
			--b;
		}
		a /= 2;
		b /= 2;
	}
	if(a == b) r += zlicz(a, c);
	return r;
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1) scanf("%d", &A[i]);
	d = 1;
	while(d <= n) d *= 2;
	FWD(u,1,n+1) tree[u+d].push_back(A[u]);
	BCK(u,d-1,0){
		merge(ALL(tree[2*u]), ALL(tree[2*u+1]), back_inserter(tree[u]));
	}
	FWD(k,1,n){
		int r = 0;
		FWD(u,1,n+1){
			if(k*(u-1)+2 > n) break;
			r += cnt(k*(u-1)+2, min(k*u+1, n), A[u]);
		}
		printf("%d ", r);
	}
	printf("\n");
	return 0;
}