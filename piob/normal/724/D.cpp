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

int n, k;
char p[100010];
bool taken[100010];

int main(){
	scanf("%d", &k);
	scanf("%s", p+1);
	n = strlen(p+1)+2;
	taken[0] = 1;
	taken[n-1] = 1;
	FWD(c,'a','z'+1){
		int lc = -1, lt = -1;
		bool ok = 1;
		FWD(i,0,n){
			if(taken[i]) lt = i;
			if(p[i] == c) lc = i;
			if(i-lt == k){
				if(i-lc >= k){
					ok = 0;
				}else{
					taken[lc] = 1;
					lt = lc;
				}
			}
		}
		if(ok) break;
		FWD(i,0,n) if(p[i] == c) taken[i] = 1;
	}
	string s;
	FWD(i,1,n-1) if(taken[i]) s.push_back(p[i]);
	sort(ALL(s));
	printf("%s\n", s.data());
	return 0;
}