#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while(getline(ss,x,c)) v.emplace_back(x); return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;

template<class T> class RMQ{
  vv<T> vals;
public:
  inline T get(int l,int r){//[l,r]
    if(l==r)return vals[0][l];
    const int d=31-__builtin_clz(l^r); //left-most distinct bit
    return max(vals[d][l],vals[d][r]);
  }
  RMQ(vector<T> &v,int e=-MOD){
    int n=v.size();
    int d=1,N=2;
    while(N<n) N*=2, ++d;
    vals.resize(d,vector<T>(N,e));
    rep(i,n) vals[0][i]=v[i];
    reps(i,1,d)rep(j,N){
      const int b=(j>>i|1)<<i;
      vals[i][j]=j>>i&1?get(b,j):get(j,b-1);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,q;
  scanf("%d%d",&n,&q);
  vector<int> a(n);
  rep(i,n)
    scanf("%d",&a[i]);
  vector<int> d(n-1),lb(n-1),rb(n-1);
  rep(i,n-1)
    d[i]=abs(a[i+1]-a[i]);
  RMQ<int> rmq(d);
  lb[0]=0; rb.back()=n-2;
  rep(i,n-1){
    if(i){
      int l=-1,r=i,m;
      while(r-l>1){
	m=(l+r)/2;
	if(rmq.get(m,i-1)>=d[i])
	  l=m;
	else
	  r=m;
      }
      lb[i]=r;
    }
    if(i+1<n-1){
      int l=i,r=n-1,m;
      while(r-l>1){
	m=(l+r)/2;
	if(rmq.get(i+1,m)>d[i])
	  r=m;
	else
	  l=m;
      }
      rb[i]=l;
    }
  }

  //cout<<d<<lb<<rb;

  int l,r;
  rep(i,q){
    scanf("%d%d",&l,&r); --l; --r; --r;
    ll re=0;
    for(int i=l;i<=r;++i){
      re+=1ll*d[i]*(i-max(l,lb[i])+1) * (min(r,rb[i])-i+1);
      //cout<<i<<":"<<d[i]<<","<<(i-max(l,lb[i])+1)<<","<<(min(r,rb[i])-i+1)<<endl;
    }
    printf("%I64d\n",re);
  }
  return 0;
}