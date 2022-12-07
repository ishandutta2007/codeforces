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

struct zawodnik{
	int i, a, b;
};

vector<zawodnik> C;

bool operator<(zawodnik a, zawodnik b){
	if(a.a == b.a) return a.b < b.b;
	return a.a > b.a;
}

bool prawo(zawodnik a, zawodnik b, zawodnik c){
	// bx = (a.a - b.a) / (a.a * b.a)
	// by = (a.b - b.b) / (a.b * b.b)
	// cx = (a.a - c.a) / (a.a * c.a)
	// cy = (a.b - c.b) / (a.b * c.b)
	// bx * cy * a.a * a.b = (a.a - b.a) * (a.b - c.b) / (b.a * c.b)
	// by * cx * a.a * a.b = (a.b - b.b) * (a.a - c.a) / (b.b * c.a)
	return ((LL)(a.a - b.a)) * (a.b - c.b) * b.b * c.a < ((LL)(a.b - b.b)) * (a.a - c.a) * b.a * c.b;
}

map<PII, bool> good;

int main(){
	scanf("%d", &n);
	PII crit;
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		zawodnik z;
		z.i = i+1;
		z.a = a;
		z.b = b;
		C.push_back(z);
	}

	sort(C.begin(), C.end());
	vector<zawodnik> H;
	FWD(i,0,n){
		if(i && C[i-1].a == C[i].a && C[i-1].b == C[i].b)
			continue;
		while(H.size() > 1 && prawo(H[SIZE(H)-2], H.back(), C[i]))
			H.pop_back();
		H.push_back(C[i]);
	}
	{
		int i = 0;
		while(i + 1 < SIZE(H) && H[i].a == H[i+1].a && H[i].b < H[i+1].b) ++i;
		int j = SIZE(H)-1;
		while(j > 0 && (H[j].b < H[j-1].b || H[j].b == H[j-1].b && H[j].a < H[j-1].a)) --j;

		while(i <= j){
			good[PII(H[i].a, H[i].b)] = 1;
			++i;
		}
	}
	vector<int> R;
	FWD(i,0,SIZE(C)) if(good[PII(C[i].a, C[i].b)]) R.push_back(C[i].i);
	sort(ALL(R));
	for(int x : R) printf("%d ", x);
	printf("\n");
	return 0;
}