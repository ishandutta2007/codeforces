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
typedef pair<K, K> PKK;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, d;
char S[200010];
char T[200010];
int P[256][256];

int main(){
	scanf("%d", &n);
	scanf("%s %s", S, T);
	FWD(i,0,n){
		if(S[i] != T[i]){
			++d;
			P[S[i]][T[i]] = 1+i;
		}
	}
	FWD(c,'a','z'+1)
		FWD(d,'a','z'+1)
			if(P[c][d] && P[d][c]){
				printf("%d\n%d %d\n", ::d-2, P[c][d], P[d][c]);
				return 0;
			}
	FWD(c,'a','z'+1)
		FWD(d,'a','z'+1)
			FWD(e,'a','z'+1)
				if(P[c][d] && P[d][e]){
					printf("%d\n%d %d\n", ::d-1, P[c][d], P[d][e]);
					return 0;
				}
	printf("%d\n-1 -1\n", d);
	return 0;
}