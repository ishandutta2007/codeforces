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
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T,U>& a){out<<"["<<a.first<<" "<<a.second<<"]";return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const map<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const multimap<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
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
#define pra(a,n)
#define praa(a,n,m)
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

const int N = 1e6;
int pos[N+1];

set<pair<int,ii>> s;
map<int,ii> mp;
int n,m;
void ins(int L,int R){
  assert(L<=R);
  if(L==1 or R==n)
      mp[L]={R-L+1,-(R-L)},
      s.insert({-(R-L),{L,R-L+1}});
  else
    mp[L]={R-L+1,-(R-L)/2},
    s.insert({-(R-L)/2,{L,R-L+1}});
}

int main()
{
  boost;
  cin>>n>>m;
  s.insert({-(n-1),{1,n}});
  mp[1]={n,-(n-1)};

  while(m--){    
    // pr(mp,s);
    int t,id;cin>>t>>id;
    // pr(t,id,pos[id]);
    if(t==1){
      assert(!s.empty());
      auto it = s.begin();
      int x = it->S.F;
      int y = it->S.S;
      int mid = x+(y-1)/2;
      if(x+y-1==n)mid=n;
      if(x==1)mid=1;
      
      assert(mp.find(x)!=mp.end());
      mp.erase(x);
      s.erase(it);

      if(x < mid) ins(x,mid-1);
      if(x + y - 1 > mid) ins(mid+1,x+y-1);
      pos[id] = mid;
      cout<<mid<<"\n";
      continue;
    }

    auto it = mp.lower_bound(pos[id]+1);
    pair<int,ii> now;
    if(it!=mp.end())now=*it;
    int L = pos[id], R = pos[id];
    if(it!=mp.begin() and sz(mp)>=1){
      --it;
      if(it->F+it->S.F==pos[id])
        L = it->F,
        assert(s.find(MP(it->S.S,MP(it->F,it->S.F)))!=s.end()),
        s.erase(MP(it->S.S,MP(it->F,it->S.F))),
        mp.erase(it);
    }
    

    if(now.F==pos[id]+1)
      R+=now.S.F,
      mp.erase(now.F),
      assert(s.find(MP(now.S.S,MP(now.F,now.S.F)))!=s.end()),
      s.erase(MP(now.S.S,MP(now.F,now.S.F)));
    
    ins(L,R);
  }

  return 0;
}