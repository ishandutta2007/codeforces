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
const ll MOD=1e9+7;
struct Mat{
  ll a,b,c,d;
  Mat(ll A=1,ll B=0,ll C=0,ll D=1){
    a=A; b=B; c=C; d=D;
  }
  static Mat e;
};
Mat Mat::e=Mat();
Mat operator*(const Mat &l,const Mat &r){
  Mat re;
  re.a=(l.a*r.a+l.b*r.c)%MOD;
  re.b=(l.a*r.b+l.b*r.d)%MOD;
  re.c=(l.c*r.a+l.d*r.c)%MOD;
  re.d=(l.c*r.b+l.d*r.d)%MOD;
  return re;
}

Mat operator+(Mat l,const Mat &r){
  (l.a+=r.a)%=MOD;
  (l.b+=r.b)%=MOD;
  (l.c+=r.c)%=MOD;
  (l.d+=r.d)%=MOD;
  return l;
}
bool operator==(const Mat &l,const Mat &r){
  return l.a == r.a &&
    l.b == r.b &&
    l.d == r.d &&
    l.c == r.c;
}
ostream& operator<<(ostream &os, const Mat &t) { return os<<"["<<t.a<<","<<t.b<<","<<t.c<<","<<t.d<<"]";}

Mat A,O(0,0,0,0);
Mat pow(int n){
  Mat re,r=A;
  //re.a=re.d=0;
  for(;n;n/=2){
    if(n%2) re=re*r;
    r=r*r;
  }
  return re;
}
const int N=(1<<17),r=11451; 
struct Seg{
  Mat a,q;
  Seg(Mat A=O,Mat q=Mat::e){
    a=A;
  }
  void comp(const Seg &ope){
    q=q*ope.q;
  }
  void clear(){
    q=Mat::e;
  }
  static Seg Ope(const Mat v=Mat()){
    Seg re; re.q=v;
    return re;
  }
  static Seg e;
};
Seg Seg::e=Seg();
ostream& operator<<(ostream &os, const Seg &t) { return os<<"("<<t.a<<","<<t.q<<")";}
Seg seg[2*N+10];
Seg operator+(Seg l,const Seg &r){
  l.a=l.a+r.a;
  return l;
}
inline void lazy_eval(int k,int a,int b){
  if(seg[k].q == Mat::e)return;
  seg[k].a=seg[k].a*seg[k].q;
  if(2*k<=2*N+5){
    seg[2*k+1].comp(seg[k]);
    seg[2*k+2].comp(seg[k]);
  }
  seg[k].clear();
}

inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

void upd(int l,int r,const Seg &ope,Seg seg[]=seg,int k=0,int a=0,int b=N){
  //cout<<"update:"<<l<<","<<r<<","<<x<<","<<d<<","<<a<<","<<b<<endl;
  lazy_eval(k,a,b);
  if(b<=l || r<=a) return; 
  if(l<=a && b<=r){
    seg[k].comp(ope);
    lazy_eval(k,a,b);
    return;
  }	
  int m=(a+b)/2;
  upd(l,r,ope,seg,2*k+1,a,m);
  upd(l,r,ope,seg,2*k+2,m,b);
  upd_node(k);
}

Seg query(int l,int r,Seg seg[]=::seg,int k=0,int a=0,int b=N){
  lazy_eval(k,a,b);
  if(b<=l || r<=a)return Seg::e; 
  if(l<=a && b<=r){return seg[k];}
  
  int m=(a+b)/2;
  Seg vl=query(l,r,seg,2*k+1,a,m);
  Seg vr=query(l,r,seg,2*k+2,m,b);
  upd_node(k);
  return vl+vr;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  A.b=A.c=A.d=1; A.a=0;
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  rep(i,n) seg[N-1+i]=Seg(pow(a[i]-1));
  rrep(i,N-1) seg[i]=seg[i*2+1]+seg[i*2+2];
  while(m--){
    int t,l,r;
    cin>>t>>l>>r; --l;
    if(t==1){
      int x;
      cin>>x;
      upd(l,r,Seg::Ope(pow(x)));
    }else{
      cout<<query(l,r).a.d<<endl;
    }
  }
  return 0;
}