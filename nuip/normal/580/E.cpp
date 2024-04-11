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
const ll MOD=1e9+9;
const int N=(1<<17),r=11451; 

struct Seg{
  ll h,q,r;
  Seg(int v=0){
    h=v; q=0;
    r=(v?::r:1);
  }
  void comp(const Seg &ope){
    q=ope.q;
  }
  void clear(){
    q=0;
  }
  static Seg Ope(int v=0){
    Seg re; re.q=v;
    return re;
  }
  static Seg e;
};
Seg Seg::e=Seg();
ostream& operator<<(ostream &os, const Seg &t) { return os<<"("<<t.h<<","<<t.q<<","<<t.r<<")";}
Seg seg[2*N+10];
Seg operator+(const Seg l,const Seg r){
  Seg re;
  re.h=(l.h*r.r%MOD+r.h)%MOD;
  re.r=l.r*r.r%MOD;
  return re;
}

vector<ll> ser(N);

inline void lazy_eval(int k,int a,int b){
  if(!seg[k].q)return;
  seg[k].h=seg[k].q*ser[b-a-1]%MOD;
  if(2*k<=2*N+5){
    seg[2*k+1].comp(seg[k]);
    seg[2*k+2].comp(seg[k]);
  }
  seg[k].clear();
}

inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

void upd(int l,int r,Seg ope,Seg seg[]=seg,int k=0,int a=0,int b=N){
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
  //cout<<a<<","<<b<<":"<<vl<<","<<vr<<endl;
  return vl+vr;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  ser[0]=1;
  rep(i,N-1) ser[i+1]=(1+ser[i]*r%MOD)%MOD;
  int n,m,t;
  cin>>n>>m>>t;
  string str;
  cin>>str;
  int a,l,r,x;
  rep(i,n)
    seg[(1<<17)-1+i]=Seg(str[i]);
  rrep(i,(1<<17)-1)
    upd_node(i);
  rep(i,t+m){
    cin>>a>>l>>r>>x; --l;
    if(a==1){
      upd(l,r,Seg::Ope(x+'0'));
    }else{
      //cout<<pii(l,r-x)<<pii(l+x,r)<<endl;
      //cout<<get(l,r-x).h<<","<<get(l+x,r).h<<endl;
      cout<<(query(l,r-x).h==query(l+x,r).h?"YES":"NO")<<endl;
    }
  }
  return 0;
}