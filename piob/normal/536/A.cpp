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

LL A, B;
int n;

LL ceil(LL a, LL b){
	return (a+b-1) / b;
}

LL calc(LL lo, LL hi, LL m){
	return max(A+(hi-1)*B, ceil((A+(lo-1)*B+A+(hi-1)*B)*(hi-lo+1)/2, m));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> A >> B >> n;
	FWD(i,0,n){
		LL lo, t, m;
		cin >> lo >> t >> m;
		if(calc(lo,lo,m) > t)
			cout << -1 << endl;
		else{
			LL a = lo;
			LL b = t + 3;
			while(b-a > 1){
				LL c = (a+b)/2;
				if(calc(lo,c,m) <= t)
					a = c;
				else
					b = c;
			}
			cout << a << endl;
		}
	}	
	return 0;
}