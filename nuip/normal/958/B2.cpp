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
//#define int LL
#define zero 0LL
using namespace std;
template<typename T> inline void maximize(T &a,T b){a=max(a,b);}
template<typename T> inline void minimize(T &a,T b){a=min(a,b);}
template<typename T> inline bool middle(T a,T b,T c){return b<=a && a<=c;}
typedef int LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<ut,VI> PQ;
inline void outputVI(VI x){REP(i,SI(x)){cout << three(i," ","") << x[i];}OUT("");}
const int SIZE1=5*1e5+1000;
const int SIZE2=5010;
const int SIZE3=400;
const int SIZE=SIZE1;
const LL INF=1LL<<30;
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
bool filled[SIZE];
int root=1;
int diameter=0;
PQ pq;
int dist[SIZE]={};
bool reached[SIZE]={};
void searchalf(){
	queue<int> qu;
	qu.push(1);
	while(!qu.empty()){
		int now=qu.front();
		qu.pop();
		REP(i,edges[now].size()){
			int next=edges[now][i];
			if(!reached[next]){
				reached[next]=true;
				qu.push(next);
				dist[next]=dist[now]+1;
				root=next;
			}
		}
	}
	diameter=dist[root];
}
int search(int now,int from){
	int maxim=0;
	REP(i,edges[now].size()){
		int next=edges[now][i];
		if(next==from) continue;
		int ret=search(next,now);
		if(maxim<ret){
			pq.push(maxim);
			maxim=ret;
		}
		else{
			pq.push(ret);
		}
	}
	return maxim+1;
}
LL solve(){
	int N;
	cin >> N;
	REP(i,N-1){
		int A,B;
		cin >> A >> B;
		edges[A].PB(B);
		edges[B].PB(A);
	}
	
	searchalf();
	cout << 1;
	if(N==1) return 0;
	int sum=0;
	sum=search(root,-1);
	REP(i,N-1){
		cout << " "<< sum;
		pq.push(0);
		sum+=pq.top();
		pq.pop();
	}	
	return 0;
}
signed main(){
	solve();
	cout << endl;
	return 0;
}