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

const int mod = 1000000007;

const K M_PI = acos(-1);

int n;
pair<K, int> ang[100010];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int x, y;
		scanf("%d %d", &x, &y);
		ang[i].st = atan2(x, y);
		ang[i].nd = i+1;
	}
	sort(ang, ang+n);
	K mi = 10;
	int p, q;
	FWD(i,1,n){
		if(ang[i].st - ang[i-1].st < mi){
			mi = ang[i].st - ang[i-1].st;
			p = ang[i-1].nd;
			q = ang[i].nd;
		}
	}
	if(ang[0].st - ang[n-1].st + 2*M_PI < mi)
		printf("%d %d\n", ang[0].nd, ang[n-1].nd);
	else
		printf("%d %d\n", p, q);
	return 0;
}