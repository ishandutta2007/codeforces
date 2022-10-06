//
//
//
//
#include <bits/stdc++.h>
#define YES "YES"
#define NO "NO"
#define YESNO OUT(three(solve(),YES,NO))
#define ECHO OUT(solve())
#define three(A,B,C) ((A)?(B):(C))
#define FOR(i,a,b)  for(LL i=(a);i< (LL)(b);i++)
#define EFOR(i,a,b) for(LL i=(a);i<=(LL)(b);i++)
#define RFOR(i,a,b) for(LL i=(a);i>=(LL)(b);i--)
#define REP(i,b) FOR(i,zero,b)
#define EREP(i,b) EFOR(i,zero,b)
#define RREP(i,b) RFOR(i,b,zero)
#define ALL(c) c.begin(),c.end()
#define UNIQUE(c) sort(ALL(c));c.erase(unique(ALL(c)),c.end())
#define MAX(c) (*max_element(ALL(c)))
#define MIN(c) (*min_element(ALL(c)))
#define MP make_pair
#define FI first
#define SE second
#define SI(x) (LL(x.size()))
#define PB push_back
#define DEBUG(a) OUT(a)
#define DEBUG2(a,b) OUT2(a,b)
#define cat cout << __LINE__ << endl
#define OUT(a) cout << (a) << endl
#define OUT2(a,b) cout << (a) <<" "<<(b) << endl
#define int LL
#define zero 0LL
using namespace std;
template<typename T> inline void maximize(T &a,T b){a=max(a,b);}
template<typename T> inline void minimize(T &a,T b){a=min(a,b);}
template<typename T> inline bool middle(T a,T b,T c){return b<=a && a<=c;}
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
inline void outputVI(VI x){REP(i,SI(x)){cout << three(i," ","") << x[i];}OUT("");}
const int SIZE1=5*1e5+1000;
const int SIZE2=5010;
const int SIZE3=400;
const int SIZE=SIZE1;
const LL INF=1LL<<60;
const long double EPS=1e-7;
string s;
ut N,M,K,X,L,Y,p;
// ut A,B,C,D,E,F,G,H,I,J,O,P,Q,R,T,U;
VI edges[SIZE];
LL A[SIZE];
LL vals[SIZE],nums[SIZE],maps[SIZE2][SIZE2],answer=zero;

////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
void init(){
	
}
LL DP[2][151][1000];
LL solve(){
	int N,L,sum=0;
	cin >> N >> K >> p;
	REP(i,N){
		cin >> A[i];
		sum+=A[i];
	}
	LL maxim=0;
	int sum2=0;	
	REP(j,51) REP(k,100) DP[0][j][k]=-INF;
	REP(j,51) REP(k,100) DP[1][j][k]=-INF;
	DP[0][0][0]=0;
	REP(t,N){
	int i=t%2;
		REP(j,K+1) REP(k,p){
			
			maximize(DP[i^1][j][(k+A[t])%p],DP[i][j][k]);
			if(j!=K) maximize(DP[i^1][j+1][0],DP[i][j][k]+(k+A[t])%p);
		//	cout << i << " "<< j << " " << k <<" "<< DP[i][j][k] << endl;
			DP[i][j][k]=-INF;
		}
			
	}
	cout << DP[N%2][K][0] << endl;
	return 0;
}
signed main(){
	solve();
	return 0;
}