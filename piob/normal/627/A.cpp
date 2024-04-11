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

LL s, x;

int main(){
	ios_base::sync_with_stdio(0);
	cin >> s >> x;
	if(x == 0){
		if(s == 0 || (s&1))
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}else{
		if(s < x || ((s-x)&1))
			cout << 0 << endl;
		else{
			FWD(b,0,50)
				if(x&(1LL<<(b)))
					if((s-x)&(1LL<<(b+1))){
						cout << 0 << endl;
						return 0;
					}
			LL res = 1;
			bool eq = (s == x);
			while(x){
				if(x&1) res *= 2;
				x /= 2;
			}
			if(eq) res -= 2;
			cout << res << endl;
		}	
	}
	return 0;
}