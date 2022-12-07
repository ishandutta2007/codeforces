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

int n, s, w;
int C[200010];

int last;
void usun_max(){
	while(C[last] == 0){
		--last;
	}
	--C[last];
}

int main(){
	scanf("%d %d", &n, &s);
	--s;
	last = n;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		if(i == s && a != 0){
			a = 0;
			++w;
		}
		++C[a];
	}
	if(n == 1){
		printf("%d\n", w);
		return 0;
	}
	w += C[0]-1;
	int zap = C[0]-1;
	int cur = 0;
	int sum = C[0];
	int b = n+3;
	FWD(i,1,n+1){
		b = min(b, cur + n - sum);
		if(sum == n) break;
		if(C[i] == 0){
			if(zap){
				--zap;
			}else{
				++C[i];
				usun_max();
				++cur;
			}
		}
		sum += C[i];
	}
	printf("%d\n", w+b);
	return 0;
}