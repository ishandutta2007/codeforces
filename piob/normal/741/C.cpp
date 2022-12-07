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
int other[200010];
int col[200010];
PII pr[200010];

int nxt(int u){
	u += 1;
	if(u == n) return 0;
	return u;
}

int nxtnxt(int u){
	u += 2;
	if(u >= n) return u-n;
	return u;
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		other[a] = b;
		other[b] = a;
		col[a] = (rand() % 2);
		col[b] = 1-col[a];
		pr[i] = PII(a, b);
	}
	n *= 2;
	bool err = 0;
	FWD(rp,0,1000){
		err = 0;
		FWD(i,0,n){
			int u = i;
			int v = nxt(i);
			int w = nxtnxt(i);
			if(col[u] == col[v] && col[v] == col[w]){
				err = 1;
				int r = rand() % 3;
				if(r == 1)
					u = v;
				else if(r == 2)
					u = w;
				col[u] = 1-col[u];
				col[other[u]] = 1-col[u];
			}
		}
		if(!err) break;
	}
	if(err){
		printf("-1\n");
	}else{
		n /= 2;
		FWD(i,0,n) printf("%d %d\n", col[pr[i].st]+1, col[pr[i].nd]+1);
	}
	return 0;
}