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

int n, k, s, t;
int price[200010];
int cap[200010];
int pos[200010];

bool check(int c){
	int pt = 0;
	FWD(i,1,k){
		int d = pos[i] - pos[i-1];
		if(d > c)
			return 0;
		if(2*d <= c)
			pt += d;
		else{
			pt += c-d + 2*(d-(c-d));
		}
	}
	return pt <= t;
}

int main(){
	scanf("%d %d %d %d", &n, &k, &s, &t);
	FWD(i,0,n)
		scanf("%d %d", &price[i], &cap[i]);
	FWD(i,1,k+1)
		scanf("%d", &pos[i]);
	sort(pos+1, pos+1+k);
	pos[k+1] = s;
	k += 2;
	int lo = 0;
	int hi = 1000000001;
	while(hi-lo>1){
		int mi = (hi+lo)/2;
		if(check(mi))
			hi = mi;
		else
			lo = mi;
	}
	int mp = 1000000001;
	FWD(i,0,n)
		if(cap[i] >= hi)
			mp = min(mp, price[i]);
	if(mp == 1000000001) mp = -1;
	printf("%d\n", mp);
	return 0;
}