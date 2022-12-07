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

int solve(int h, vector<PII> A, vector<PII> B){
	int c = 0;
	priority_queue<int> MA, MB;
	sort(ALL(A), greater<PII>());
	sort(ALL(B), greater<PII>());
	for(;;){
		while(!A.empty() && A.back().st <= h){
			MA.push(A.back().nd);
			A.pop_back();
		}
		if(MA.empty()) break;
		++c;
		h += MA.top();
		MA.pop();
		swap(A, B);
		swap(MA, MB);
	}
	return c;
}

int n, h;
vector<PII> A, B;

int main(){
	scanf("%d %d", &n, &h);
	FWD(i,0,n){
		int t, c, m;
		scanf("%d %d %d", &t, &c, &m);
		if(t == 0) A.push_back(PII(c, m));
		else B.push_back(PII(c, m));
	}
	printf("%d\n", max(solve(h, A, B), solve(h, B, A)));
	return 0;
}