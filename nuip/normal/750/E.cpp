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
#define error(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while(getline(ss,x,c)) v.emplace_back(x); return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;
const int INF=1e8;
int nn=1<<18;

struct Seg{
  array<array<int,7>,7> mn;
  Seg(){
    rep(i,7)rep(j,7) mn[i][j]=INF;
    rep(i,7) mn[i][i]=0;
  }
  Seg(char c){
    rep(i,7)rep(j,7) mn[i][j]=INF;
    rep(i,7) mn[i][i]=0;
    c-='0';
    if(c==2){
      mn[0][1]=0;
      mn[0][0]=1;
    }else if(c==0){
      mn[1][2]=0;
      mn[1][1]=1;
    }else if(c==1){
      mn[2][3]=0;
      mn[2][2]=1;
    }else if(c==6){
      mn[3][4]=0; mn[5][6]=0;
      mn[3][3]=1; mn[5][5]=1;
    }else if(c==7){
      mn[3][5]=0;
      mn[3][3]=1;
    }
  }
  static Seg e;
};
vector<Seg> dat(2*nn);
Seg Seg::e=Seg();
Seg sINF;

Seg operator+(const Seg &l,const Seg &r){
  Seg re=sINF;
  rep(c,7)rep(b,c+1)rep(a,b+1) MN(re.mn[a][c], l.mn[a][b]+r.mn[b][c]);
  return re;
}
//ostream& operator<<(ostream &os, const Seg &t) { return os<<"["<<t.mn<<")";}
template<class T=Seg> void upd(int k,T a,vector<T> &dat=dat){
  k+=dat.size()/2-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

//(l,r,0,0,nn)
template<class T=Seg> T query(int a,int b,const vector<T> &dat=dat,int k=0,int l=0,int r=-1){
  if(r<0) r=dat.size()/2;
  if(r<=a || b<=l)return T::e;
  if(a<=l && r<=b) return dat[k];
  T lv=query(a,b,dat,k*2+1,l,(l+r)/2) ,rv= query(a,b,dat,k*2+2,(l+r)/2,r);
  // cout<<pii(l,r);
  // auto tmp=lv+rv;
  // rep(j,7){rep(k,7)cout<<tmp.mn[j][k]<<",";cout<<endl;}cout<<endl;    
  return lv+rv;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  rep(i,7)sINF.mn[i][i]=INF;
  int n,q;
  string s;
  cin>>n>>q>>s;
  rep(i,n) dat[nn-1+i]=Seg(s[i]);
  rrep(i,nn-1) dat[i]=dat[i*2+1]+dat[i*2+2];
  rep(i,n){
    //rep(j,7){rep(k,7)cout<<dat[nn-1+i].mn[j][k]<<",";cout<<endl;}cout<<endl;
  }
  Seg tmp=Seg('2')+Seg('0')+Seg('1')+Seg('6');
  //rep(j,7){rep(k,7)cout<<tmp.mn[j][k]<<",";cout<<endl;}cout<<endl;
  rep(i,q){
    int x,y;
    cin>>x>>y; --x;
    //cout<<pii(x,y)<<endl;
    //auto tmp=query(x,y);
    //rep(j,7){rep(k,7)cout<<tmp.mn[j][k]<<",";cout<<endl;}cout<<endl;    
    int re=query(x,y).mn[0][5];
    cout<<(re==INF?-1:re)<<endl;
  }
  return 0;
}