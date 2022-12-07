#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWdistsort(a,b,c,d) for(int a=(b); a<(c); a+=d)
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

const int MAXN = 100010;

char buff[210000];
int A[256], B[256];

void read(int T[]){
	scanf(" %[^\n]s", buff);
	int n = strlen(buff);
	FWD(i,0,n) ++T[buff[i]];
}

bool check(){
	A[' '] = B[' '] = 0;
	FWD(i,0,256) if(B[i] > A[i]) return 0;
	return 1;
}

int main(){
	//int z;
	//scanf("%d", &z);
	//while(z--){
		read(A);
		read(B);
		printf(check()?"YES\n":"NO\n");
		FWD(i,0,256) A[i] = B[i] = 0;
	//}
	return 0;
}