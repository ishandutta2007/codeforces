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
template<class T,class U>
ostream& operator<<(ostream &out,const pair<T,U>&_){out<<"["<<_.first<<" , "<<_.second<<"] "; return out;}
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

template<typename XXX>
struct BIT1 // Point update,query
{
  vector<XXX> t;XXX n;BIT1(){n=0;}
  BIT1(XXX sz){ n=sz; t=vector<XXX>(sz+1,0);}
  void clr(XXX sz){ n=sz; t=vector<XXX>(sz+1,0);}
  void upd(XXX i, XXX val){ while(i<=n) t[i]+=val, i+=i&-i;}
  XXX qry(XXX i){XXX ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
};
int main()
{
  boost;
  int n,k;cin>>n>>k;
  vi p(n),pos(n+1);
  FOR(i,0,n-1)cin>>p[i],pos[p[i]]=i;
  vi b(k);
  FOR(i,0,k-1)cin>>b[i];
  int j=0;
  vi can(n,0);
  FOR(i,0,n-1){
    if(j==k)break;
    if(p[i]==b[j]){
      ++j;
      can[i]=1;
    }
  }
  set<ii> s;
  vi pg(n,-1),ng(n,n);
  FOR(i,0,n-1){
    if(s.empty()){if(can[i])s.insert(MP(p[i],i));continue;}
    if(!can[i]){
      auto it = s.lower_bound(MP(p[i],-1));
      if(it==s.begin())continue;
      --it;
      pg[i]=it->S;
      continue; 
    }
    while(!s.empty() and s.rbegin()->F > p[i])s.erase(--s.end());
    s.insert(MP(p[i],i));
  }
  s.clear();
  NFOR(i,n-1,0){
    if(s.empty()){if(can[i])s.insert(MP(p[i],i));continue;}
    if(!can[i]){
      auto it = s.lower_bound(MP(p[i],-1));
      if(it==s.begin())continue;
      --it;
      ng[i]=it->S;
      continue;
    }
    while(!s.empty() and s.rbegin()->F > p[i])s.erase(--s.end());
    s.insert(MP(p[i],i));
  }
  
  BIT1<int> bt(n+69);
  ll ans=0;

  FOR(i,1,n){
    if(can[pos[i]])continue;
    int x=0;
    x+=bt.qry(pg[pos[i]]+2);
    x-=bt.qry(ng[pos[i]]+1);
    x+=ng[pos[i]]-1-pg[pos[i]];
  
    ans+=x;
    bt.upd(pos[i]+2,1);
  }
  cout<<ans;
  return 0;
}