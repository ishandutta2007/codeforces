#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X)=(0);(X)<(Y);++(X))
#define REP rep
#define rrep(X,Y) for(int (X)=(Y)-1;(X)>=0;--(X))
#define all(x) (x).begin(),(x).end()
#define eb pb

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for(int (X)=S;(X)<(Y);++(X))
#define rreps(X,S,Y) for(int (X)=(Y)-1;(X)>=(S);--(X))

template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define fst first
#define snd second
//#define all(c) ((c).begin()),((c).end())
LL ST=1299,ED=1300;
const LL INF=(1ll<<50);
struct graph{
  typedef LL flow_type;
  struct edge{
    int src,dst;
    flow_type capacity,flow;
    size_t rev;
    int number;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n): n(n),adj(n){}
  void add_edge(int src,int dst,flow_type capacity,int number){
    adj[src].push_back({src,dst,capacity,0,adj[dst].size(),number});
    adj[dst].push_back({dst,src,0,0,adj[src].size()-1,number});
  }
  flow_type max_flow(int s,int t){
    vector<int> level(n),iter(n);
    function<int(void)> levelize =
      [&](){
	level.assign(n,-1); level[s]=0;
	queue<int> Q;Q.push(s);
	while(!Q.empty()){
	  int u=Q.front();Q.pop();
	  if(u==t) break;
	  for(auto &e:adj[u]){
	    if(e.capacity > e.flow && level[e.dst]<0){
	      Q.push(e.dst);
	      level[e.dst]=level[u]+1;
	    }
	  }
	}
	return level[t];
      };
    function<flow_type(int,flow_type)> augment=
      [&](int u,flow_type cur){
	if(u==t) return cur;
	for(int &i=iter[u];i<adj[u].size();++i){
	  edge &e=adj[u][i],&r=adj[e.dst][e.rev];
	  if(e.capacity > e.flow && level[u] < level[e.dst]){
	    flow_type f=augment(e.dst,min(cur,e.capacity - e.flow));
	    if(f>0 ){
	      e.flow+=f;
	      r.flow-=f;
	      return f;
	    }
	  }
	}
	return flow_type(0);
	
      };
    for(int u=0;u<n;++u)
      for(auto &e: adj[u]) e.flow = 0;

    flow_type flow=0;
    while(levelize() >= 0){
      fill(all(iter),0);
      for(flow_type f; (f= augment(s,INF)) > 0;)
	flow += f;
    }
    return flow;
    }
};
LL test,n,m,k;
const int SIZE=1000;
LL A[SIZE],B[SIZE];
LL DEG[SIZE];
LL answer[SIZE];
int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  cin >> test;
  REP(ttttt,test){
    LL sums=0;
    cin >> n >> m >> k;
    ST=n+m+2;
    ED=n+m+3;
    graph g=graph(ED+1);
    EFOR(i,1,n) DEG[i]=0;
    REP(i,m){
      int a,b;
      cin >> A[i] >> B[i];
      g.add_edge(A[i],i+n+1,1,i);
      g.add_edge(B[i],i+n+1,1,i);
      g.add_edge(i+n+1,ED,1,i);
      DEG[A[i]]++;
      DEG[B[i]]++;
    }
    EFOR(i,1,n){
      g.add_edge(ST,i,max(0LL,2*(DEG[i]-k)),-1);
      sums+=max(0LL,2*(DEG[i]-k));
    }
    LL ans=g.max_flow(ST,ED);
    if(ans!=sums){
      REP(i,m){
	if(i) cout << " ";
	cout << 0 ;
      }
      cout << endl;
    }else{
      int now=1;
      int twin=0;
      REP(i,m) answer[i]=0;
      EFOR(i,1,n){
	REP(j,g.adj[i].size()){
	  if(g.adj[i][j].flow==1){
	    if(twin){
	      answer[g.adj[i][j].number]=now;
	      now++;
	      twin=0;
	    }else{
	      answer[g.adj[i][j].number]=now;
	      twin++;
	    }
	  }
	}
      }
      REP(i,m){
	if(i) cout << " ";
	if(answer[i]) cout << answer[i];
	else{
	  cout << now;
	  now++;
	}
      }
      cout << endl;
    }
   
  }
  return 0;
}