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

const int MAXN = 200010;

struct tree{
	int data[MAXN];
	void add(int i, int v){ for (; i < MAXN; i |= i + 1) data[i] += v; }
	int sum(int i){ int s=0; while(i>=0) { s+=data[i]; i=(i&(i+1))-1; } return s; }
	int get(int i){
		return sum(i) - sum(i-1);
	}
};

int n, k, a, b, q;
tree A, B;

int main(){
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
	FWD(i,0,q){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int d, c, ch;
			scanf("%d %d", &d, &c);

			ch = min(A.get(d) + c, a) - A.get(d);
			A.add(d, ch);

			ch = min(B.get(d) + c, b) - B.get(d);
			B.add(d, ch);
		}else{
			int d;
			scanf("%d", &d);
			printf("%d\n", B.sum(d-1) + A.sum(n) - A.sum(min(n,d-1+k)));
		}
	}
	return 0;
}