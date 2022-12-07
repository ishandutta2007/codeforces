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

int n, L, X, Y;
set<int> D;

int main(){
	scanf("%d %d %d %d", &n, &L, &X, &Y);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		D.insert(a);
	}
	bool okX = 0, okY = 0;
	for(int a : D) okX |= (D.find(a-X) != D.end()), okY |= (D.find(a-Y) != D.end());
	if(okX && okY){
		printf("0\n");
		return 0;
	}
	if(okX || okY){
		printf("1\n%d\n", okX?Y:X);
		return 0;
	}
	for(int a : D)
		if(D.find(a-X+Y) != D.end() && a >= X){
			printf("1\n%d\n", a-X);
			return 0;
		}
	for(int a : D)
		if(D.find(a-X+Y) != D.end() && a + Y <= L){
			printf("1\n%d\n", a+Y);
			return 0;
		}
	for(int a : D)
		if(D.find(a+X+Y) != D.end()){
			printf("1\n%d\n", a+X);
			return 0;
		}
	printf("2\n%d %d\n", X, Y);
	return 0;
}