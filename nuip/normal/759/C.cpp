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
const int N=(1<<17);

struct Seg{
  int sum,q;
  Seg(int v=0):sum(v),q(0){
  }
  static Seg e;
};
Seg Seg::e=Seg();
//ostream& operator<<(ostream &os, const Seg &t) { return os<<"("<<t.h<<","<<t.q<<","<<t.r<<")";}
Seg seg[2*N+10];
Seg operator+(const Seg l,const Seg r){
  return Seg(min(l.sum,r.sum));
}
inline void lazy_eval(int k,int a,int b){
  if(!seg[k].q)return;
  seg[k].sum+=seg[k].q;
  if(2*k<=2*N+5){
    seg[2*k+1].q+=seg[k].q;
    seg[2*k+2].q+=seg[k].q;
  }
  seg[k].q=0;
}

//inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

void upd(int l,int r,int d,Seg seg[]=seg,int k=0,int a=0,int b=N){
  //cout<<"update:"<<l<<","<<r<<","<<x<<","<<d<<","<<a<<","<<b<<endl;
  lazy_eval(k,a,b);
  if(b<=l || r<=a) return; 
  if(l<=a && b<=r){
    seg[k].q+=d;
    lazy_eval(k,a,b);
    return;
  }	
  int m=(a+b)/2;
  upd(l,r,d,seg,2*k+1,a,m);
  upd(l,r,d,seg,2*k+2,m,b);
  seg[k].sum=min(seg[2*k+1].sum,seg[2*k+2].sum);
}

int query(int l,int r,Seg seg[]=::seg,int k=0,int a=0,int b=N){
  lazy_eval(k,a,b);
  if(b<=l || r<=a)return MOD;
  if(l<=a && b<=r){return seg[k].sum;}
  
  int m=(a+b)/2;
  int vl=query(l,r,seg,2*k+1,a,m);
  int vr=query(l,r,seg,2*k+2,m,b);
  seg[k].sum=min(seg[2*k+1].sum,seg[2*k+2].sum);
  //cout<<a<<","<<b<<":"<<vl<<","<<vr<<endl;
  return min(vl,vr);
}

int main(){
  int n;
  scanf("%d",&n);
  vector<int> p(n),ts(n),xs(n);
  rep(i,n){
    int t,x=-1;
    scanf("%d%d",&p[i],&t); --p[i];
    if(t) scanf("%d",&x);
    xs[p[i]]=x;
    ts[p[i]]=t;
  }
  for(int i:p){
    upd(0,i+1,ts[i]?-1:1);
    if(query(0,n)<0){
      int l=0,r=n;
      while(r-l>1){
	int m=(l+r)/2;
	if(query(m,n)<0) l=m;
	else r=m;
      }
      printf("%d\n",xs[l]);
    }else{
      printf("-1\n");
    }
  }
  return 0;
}