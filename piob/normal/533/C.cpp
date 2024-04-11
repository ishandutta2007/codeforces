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

int xp, yp, xv, yv;

int main(){
	scanf("%d %d %d %d", &xp, &yp, &xv, &yv);
	for(;;){
		int d = xv - yv;
		bool mov = 0;
		if(xp - yp < d){
			if(yp){
				--yp;
				mov = 1;
			}
		}else if(xp - yp > d){
			if(xp){
				--xp;
				mov = 1;
			}
		}
		if(!mov){
			if(xp == 0) --yp;
			else if(yp == 0) --xp;
		}
		if(xp == 0 && yp == 0){
			printf("Polycarp\n");
			return 0;		
		}
		if(xv - 1 == xp && yv - 1 == yp){
			printf("Polycarp\n");
			return 0;
		}
		--xv;
		--yv;
		xv = max(xv, 0);
		yv = max(yv, 0);
		if(xv == 0 && yv == 0){
			printf("Vasiliy\n");
			return 0;
		}
	}
	return 0;
}