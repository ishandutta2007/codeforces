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
multiset<LL> S;
set<int> E;
LL V[100010];

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		scanf("%lld", &V[i+1]);
		V[i+1] += V[i];
	}
	E.insert(0);
	E.insert(n+1);
	S.insert(V[n+1]);
	FWD(i,0,n){
		int p;
		scanf("%d", &p);
		auto it = E.insert(p).first;
		auto pr = prev(it);
		auto nx = next(it);
		S.erase(S.find(V[*nx] - V[*pr+1]));
		S.insert(V[*it] - V[*pr+1]);
		S.insert(V[*nx] - V[*it+1]);
		printf("%lld\n", *prev(S.end()));
	}
	return 0;
}