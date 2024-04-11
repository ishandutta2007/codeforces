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

const int N = 1e5;

int main()
{
  boost;
  int n;cin>>n;
  vi a(n);FOR(i,0,n-1)cin>>a[i];
  sort(all(a));
  int x = 1;
  FOR(i,0,n-1){
    if(a[i]>=x)++x;
  }
  cout<<x;
  return 0;
}