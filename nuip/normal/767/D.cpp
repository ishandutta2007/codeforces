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
int t;
int ok(vector<int> &v){
  int n=v.size();
  rep(i,n) if(v[i]<i/t) return 0;
  return 1;
}
int main(){
  int n,m;
  scanf("%d%d%d",&n,&m,&t);
  vector<int> a(n);
  vector<pii> b(m);
  rep(i,n) scanf("%d",&a[i]);
  rep(i,m) scanf("%d",&b[i].X), b[i].Y=i;
  sort(all(b)); sort(all(a));
  if(ok(a)==0){
    printf("-1\n");
    return 0;
  }
  int l=0,r=m+1;
  while(r-l>1){
    int m=(l+r)/2;
    vector<int> v; v.reserve(n+m);
    int i=0,j=b.size()-m;
    while(i<a.size() || j<b.size()){
      if(i==a.size() || j<b.size() && a[i]>b[j].X) v.pb(b[j++].X);
      else v.pb(a[i++]);
    }
    //out(m,v,1);
    if(ok(v)) l=m;
    else r=m;
  }
  printf("%d\n",l);
  rep(i,l) printf("%d ",b[m-1-i].Y+1); printf("\n");
  return 0;
}