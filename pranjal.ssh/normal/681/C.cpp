#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;


#define TRACE

#ifdef TRACE
#define prc(a) cerr<<#a<<" : ";for(auto it:a)cerr<<it<<" ";cerr<<endl;
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
} 
#else
#define trace(...)
#define prc(a)
#endif


#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

const int N = 1e5;
pair<string,int> op[N+1];
vector<pair<int,pair<string,int>>> ans;
int main()
{
  boost;
  int n;cin>>n;
  FOR(i,1,n){cin>>op[i].F;if(op[i].F!="removeMin")cin>>op[i].S;}
  priority_queue<int,vector<int>,greater<int>> pq;
  int ctr = 0;
  vi pos;
  FOR(i,1,n){
    string s = op[i].F;
    int x = op[i].S;
    if(s=="insert"){pq.push(x);ans.pb({++ctr,op[i]});continue;}
    if(s=="removeMin"){
      if(pq.empty()) 
        ans.pb({++ctr,{"insert",-1e9}}),
        ans.pb({++ctr,op[i]});
      else
        pq.pop(),
        ans.pb({++ctr,op[i]});
      continue;
    }
    if(s=="getMin"){
      if(pq.empty()){
        ans.pb({++ctr,{"insert",x}}),
        ans.pb({++ctr,op[i]}),
        pq.push(x);
        continue;
      }
      while(!pq.empty() and pq.top()<x)
        ans.pb({++ctr,{"removeMin",-1}}),
        pq.pop();
      if(pq.empty() or pq.top()!=x)
        ans.pb({++ctr,{"insert",x}}),
        pq.push(x);
        
      ans.pb({++ctr,{"getMin",x}});
    }
  }
  cout<<sz(ans)<<"\n";
  for(auto it:ans){
    cout<<it.S.F;
    if(it.S.F!="removeMin")cout<<" "<<it.S.S;
    cout<<"\n";
  }

  return 0;
}