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

struct frac{
	LL p, q;
};

bool operator<(frac a, frac b){
	return a.p * b.q < a.q * b.p;
}

int n;
LL x[200010];
LL s[200010];
vector<int> p;
frac res;

int best_i, best_k;

LL sum(int a, int b){
	return s[b] - s[a];
}

frac val(int i, int k){
	return frac{sum(i-k, i+1) + sum(n-k, n) - x[i]*(2*k+1), 2*k+1};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	FWD(i,0,n) cin >> x[i];
	sort(x, x+n);
	res.p = -1;
	res.q = 1;
	FWD(i,0,n) s[i+1] = s[i] + x[i];
	FWD(i,0,n){
		int lo = 0;
		int hi = min(i, n-i-1);
		while(hi - lo > 10){
			int mi0 = (2*lo + hi) / 3;
			int mi1 = (lo + 2*hi) / 3;
			if(val(i, mi0) < val(i,mi1))
				lo = mi0;
			else
				hi = mi1;
		}
		FWD(k,lo,hi+1)
			if(res < val(i,k)){
				res = val(i, k);
				best_i = i;
				best_k = k;
			}
	}

	printf("%d\n", 2*best_k+1);
	FWD(i,best_i-best_k,best_i+1) printf("%d ", (int)x[i]);
	FWD(i,n-best_k,n) printf("%d ", (int)x[i]);
	printf("\n");
	return 0;
}