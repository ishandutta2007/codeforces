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

int n, t, r;
vector<int> Q[110];

int main(){
	scanf("%d %d", &n, &t);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		Q[t-a].push_back(b);
	}
	vector<int> C;
	vector<int> D;
	BCK(i,t,-1){
		//printf("poziom %d\n", i);
		for(int i = 0; i+1 < SIZE(C); i += 2) D.push_back(C[i] + C[i+1]);
		if(SIZE(C)&1) D.push_back(C.back());
		for(int q : Q[i]) D.push_back(q);
		sort(D.begin(), D.end(), greater<int>());
		//printf("D: "); for(int d : D) printf("%d ", d); printf("\n");
		//printf("scinamy do %lld\n", (1LL << i));
		if(i < 15) while(SIZE(D) > (1 << i)) D.pop_back();
		swap(C, D);
		D.clear();
	}
	printf("%d\n", C.back());
	return 0;
}