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

const int MAXN = 300010;

int n;
int P[MAXN];
LL res;

void read(){
	scanf("%d", &n);
	vector<PII> V(n);
	FWD(i,0,n) scanf("%d %d", &V[i].st, &V[i].nd);
	sort(ALL(V));
	FWD(i,0,n) P[i] = V[i].nd;
}

int mi[MAXN], ma[MAXN];
int cnt[2*MAXN];

void solve(int p, int k){
	if(k-p < 2){
		res += k-p;
		return;
	}

	int m = (p+k)/2;
	solve(p, m);
	solve(m, k);
	
	FWD(r,0,2){
		//printf("zliczam [%d, %d) x [%d, %d)\n", p, m, m, k);
		//FWD(i,p,k) printf("%d ", P[i]); printf("\n");

		mi[m] = ma[m] = P[m];
		FWD(i,m+1,k) mi[i] = min(mi[i-1], P[i]);
		FWD(i,m+1,k) ma[i] = max(ma[i-1], P[i]);

		// min, max in [p, m)

		int cmi = n+1;
		int cma = -1;
		BCK(i,m-1,p-1){
			cmi = min(cmi, P[i]);
			cma = max(cma, P[i]);
			int j = i + cma - cmi;
			if(m <= j && j < k && cmi < mi[j] && ma[j] < cma){
				++res;
				//printf("	[%d, %d]\n", i, j);
			}
		}

		// min in [p, m), max in [m, k)

		// max - min = j - i
		// i - min = j - max
		cmi = n+1, cma = -1;
		int lo = m, hi = m;
		BCK(i,m-1,p-1){
			cmi = min(cmi, P[i]);
			cma = max(cma, P[i]);
			while(hi < k && cmi < mi[hi]){
				++cnt[hi-ma[hi]+MAXN];
				++hi;
			}
			while(lo < hi && ma[lo] < cma){
				--cnt[lo-ma[lo]+MAXN];
				++lo;
			}
			res += cnt[i-cmi+MAXN];
			//printf("	[%d, ?] x %d\n", i, cnt[i-cmi+MAXN]);
		}
		FWD(i,m,k) cnt[i-ma[i]+MAXN] = 0;

		reverse(P+p, P+k);
		m = (p+k) - m;
	}
}

int main(){
	read();
	solve(0,n);
	cout << res << endl;
	return 0;
}