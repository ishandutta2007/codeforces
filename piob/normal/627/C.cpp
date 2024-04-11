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

int d, tot, cur, n;
int X[200010];
int P[200010];
vector<PII> Vp;
deque<int> Dm;
LL res;

void Dpush(int p){
	while(!Dm.empty() && Dm.back() > p) Dm.pop_back();
	Dm.push_back(p);
}

void Dpop(int p){
	if(!Dm.empty() && Dm.front() == p) Dm.pop_front();
}

int Dmin(){
	if(Dm.empty()) return 1000*1000 + 3;
	return Dm.front();
}

int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d %d %d", &d, &tot, &n);
	cur = tot;
	X[0] = 0;
	P[0] = 1000*1000 + 3;
	FWD(i,1,n+1){
		int x, p;
		scanf("%d %d", &x, &p);
		Vp.push_back(PII(x, p));
	}
	sort(Vp.begin(), Vp.end());
	FWD(i,0,n){
		X[i+1] = Vp[i].st;
		P[i+1] = Vp[i].nd;
	}
	X[n+1] = d;
	P[n+1] = P[0];
	int a = 0, b = 0;
	while(a < n+1){
		while(b <= n+1 && X[b] - X[a] <= cur){
			Dpush(P[b]);
			++b;
		}
		if(cur == tot || Dmin() < P[a] || b > n+1){
			if(X[a+1] - X[a] > tot){
				printf("-1\n");
				return 0;
			}
			assert(cur >= X[a+1] - X[a]);
			cur -= X[a+1] - X[a];
			Dpop(P[a]);
			++a;
		}else{
			res += P[a] * (LL)(min(tot, X[b]-X[a]) - cur);
			cur = min(tot, X[b]-X[a]);
		}
	}
	cout << res << endl;
	return 0;
}