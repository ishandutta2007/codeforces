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

int n, a, b, k;
char M[200010];

int main(){
	scanf("%d %d %d %d", &n, &a, &b, &k);
	scanf("%s", M+1);
	M[0] = '1';
	M[n+1] = '1';
	n+=2;
	int lkp = 0;
	int c = 0;
	FWD(i,1,n){
		if(M[i] == '1'){
			c += (i - lkp - 1) / b;
			lkp = i;
		}
	}
	c = c-a+1;
	printf("%d\n", c);
	lkp = 0;
	FWD(i,1,n){
		if(M[i] == '1'){
			lkp = i;
		}else{
			if(i == lkp + b){
				lkp = i;
				if(c){
					printf("%d ", i);
					--c;
				}
			}
		}
	}
	printf("\n");
	return 0;
}