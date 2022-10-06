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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
vector<int> convex_hull(vector<P> ps_) {
  int n = ps_.size(), k = 0;
  vector<pair<P,int>> ps(n);
  rep(i,n){
    ps[i].X=ps_[i]; ps[i].Y=i;
  }
  sort(ps.begin(), ps.end());
  vector<int> ch(2*n);
  for (int i = 0; i < n; ch[k++] = i++) // lower-hull
    while (k >= 2 && ccw(ps[ch[k-2]].X, ps[ch[k-1]].X, ps[i].X) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = i--) // upper-hull
    while (k >= t && ccw(ps[ch[k-2]].X, ps[ch[k-1]].X, ps[i].X) <= 0) --k;
  ch.resize(k-1);
  rep(i,ch.size())
    ch[i]=ps[ch[i]].Y;
  return ch;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int i,j,k;
  int n,s,r;
  scanf("%d",&n);
  vector<P> ps(n);
  /*  if(n<3){
    if(n==1)printf("1\n");
    if(n==2){
      vector<pii> v(2);
      vector<int> re;
      rep(i,n)
       scanf("%d %d",&v[i].X,&v[i].Y);
      rep(i,n)
	if(v[i].X<v[1-i].X || v[i].Y<v[1-i].Y)
	  re.pb(i+1);
      sort(all(re));
      rep(i,re.size())
		  printf("%d%c",re[i],(i+1==re.size()?'\n':' '));
    }
    return 0;
    }*/
  double minx=100,miny=100;
  vector<pii> v(n);
  map<pii,vector<int>> mp;
  rep(i,n){
    scanf("%d %d",&s,&r);
    v[i]=pii(s,r);
    mp[v[i]].pb(i);
    ps[i]=P(double(1)/s,double(1)/r);
    minx=min(minx,ps[i].real());
    miny=min(miny,ps[i].imag());
  }
  ps.pb(P(minx-EPS,5));
  ps.pb(P(5,miny-EPS));
  vector<int> conv=convex_hull(ps);
  //cout<<ps<<conv;
  sort(all(conv));
  conv.pop_back(); conv.pop_back();
  vector<int> re;
  rep(i,conv.size())
    for(int &val:mp[v[conv[i]]])
      re.pb(val);
  sort(all(re));
  re.erase(unique(all(re)),re.end());
  rep(i,re.size())
    printf("%d%c",re[i]+1,(i+1==re.size()?'\n':' '));
  return 0;
}