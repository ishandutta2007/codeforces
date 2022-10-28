#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int neg(int x,int m=INF){x=-x;return norm(x);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}


const ll INFF = numeric_limits<ll>::max() / 4;

struct MinCostMaxFlow {
  int N;
  vvll cap, flow, cost;
  vi found;
  vll dist, pi, width;
  vii dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, vll(N)), flow(N, vll(N)), cost(N, vll(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, ll cap, ll cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, ll cap, ll cost, int dir) {
    ll val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  ll Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INFF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INFF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INFF);
    return width[t];
  }

  pair<ll, ll> GetMaxFlow(int s, int t) {
    ll totflow = 0, totcost = 0;
    while (ll amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    string t;
    cin>>t;
    int n;
    cin>>n;
    MinCostMaxFlow FF(n+26+2);
    int f[26];
    
    C(f,0);
    tr(t,it)f[*it-'a']++;
    
    
    FOR(i,n+1,n+26)FF.AddEdge(i,n+27,f[i-(n+1)],0);
    FOR(i,0,n-1)
    {
    	string x;
    	cin>>x;
    	int y;cin>>y;
    	FF.AddEdge(0,i+1,y,0);
    	int a[26];
    	C(a,0);
    	tr(x,it)a[*it-'a']++;
    	FOR(j,0,25)
    	{
    		FF.AddEdge(i+1,n+1+j,a[j],i+1);
    	}
    }
    pair<ll,ll> ans=FF.GetMaxFlow(0,n+27);
    
    if(ans.F!=t.length())cout<<"-1\n";
    else
    cout<<ans.S<<"\n";
    
	return 0;
}