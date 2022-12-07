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
char buff[110];

bool check(){
	FWD(d,1,n){
		for(int i=0; i+4*d<n; ++i){
			bool ok = 1;
			if(buff[i] == '.') ok = 0;
			if(buff[i+d] == '.') ok = 0;
			if(buff[i+2*d] == '.') ok = 0;
			if(buff[i+3*d] == '.') ok = 0;
			if(buff[i+4*d] == '.') ok = 0;
			if(ok) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d", &n);
	scanf("%s", buff);
	printf(check()?"yes\n":"no\n");
	return 0;
}