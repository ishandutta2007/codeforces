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
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
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
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;
const int MAX_N=(1<<17);
int nn=MAX_N;

int n,m;

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(data[y]<data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
};

struct Seg{
  vector<int> l,r,lid,rid;
  int cnt,bd;
  Seg():l(n),r(n),lid(n),rid(n),cnt(0),bd(0){}
  static Seg e;
};
vector<Seg> dat;
Seg Seg::e=Seg();

Seg operator+(const Seg &l,const Seg &r){
  if(l.bd==0) return r;
  if(r.bd==0) return l;
  Seg re;
  UF uf(l.bd+r.bd);
  rep(i,n)if(l.rid[i]==r.lid[i]) uf.unite(l.r[i],r.l[i]+l.bd);
  vector<int> id(l.bd+r.bd,-1);
  int cnt=0,cc=0;
  for(int i:l.l)if(id[uf.root(i)]<0){
      id[uf.root(i)]=cnt++;
  }
  for(int i:r.r)if(id[uf.root(i+l.bd)]<0){
      id[uf.root(i+l.bd)]=cnt++;
  }
  for(int x:uf.data)if(x<0) ++cc;
  //out(uf.data,id,cnt,1);
  re.cnt=l.cnt+r.cnt+cc-cnt;
  re.bd=cnt;
  rep(i,n) re.l[i]=id[uf.root(l.l[i])];
  rep(i,n) re.r[i]=id[uf.root(r.r[i]+l.bd)];
  re.lid=l.lid; re.rid=r.rid;
  return re;
}
void add(Seg &l,const Seg &r){
  if(r.bd==0) return;
  if(l.bd==0){ l=r; return;}
  UF uf(l.bd+r.bd);
  rep(i,n)if(l.rid[i]==r.lid[i]) uf.unite(l.r[i],r.l[i]+l.bd);
  vector<int> id(l.bd+r.bd,-1);
  int cnt=0,cc=0;
  for(int i:l.l)if(id[uf.root(i)]<0){
      id[uf.root(i)]=cnt++;
  }
  for(int i:r.r)if(id[uf.root(i+l.bd)]<0){
      id[uf.root(i+l.bd)]=cnt++;
  }
  for(int x:uf.data)if(x<0) ++cc;
  l.cnt+=r.cnt+cc-cnt;
  rep(i,n) l.l[i]=id[uf.root(l.l[i])];
  rep(i,n) l.r[i]=id[uf.root(r.r[i]+l.bd)];
  l.bd=cnt;
  l.rid=r.rid;
}
ostream& operator<<(ostream &os, const Seg &t) { return os<<"["<<t.l<<t.r<<t.lid<<t.rid<<","<<t.bd<<","<<t.cnt<<")";}
template<class T=Seg> void upd(int k,T a,vector<T> &dat=dat){
  k+=dat.size()/2-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

//(l,r,0,0,nn)
void query(Seg &re,int a,int b,const vector<Seg> &dat=dat,int k=0,int l=0,int r=-1){
  if(r<0) r=dat.size()/2;
  if(r<=a || b<=l)return;
  if(a<=l && r<=b){
    add(re,dat[k]);
    return;
  }
  query(re,a,b,dat,k*2+1,l,(l+r)/2);
  query(re,a,b,dat,k*2+2,(l+r)/2,r);
}

int tb[112345][11];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int q;
  //n=10; m=q=100000;
  cin>>n>>m>>q;
  dat.resize(2*nn);
  //rep(i,n)rep(j,m) tb[j][i]=rand()%1000000+1;
  rep(i,n)rep(j,m) cin>>tb[j][i];
  rep(i,m){
    int cnt=0;
    rep(j,n){
      dat[nn-1+i].l[j]=dat[nn-1+i].r[j]=(j&&tb[i][j]==tb[i][j-1]?cnt-1:cnt++);
      dat[nn-1+i].lid[j]=dat[nn-1+i].rid[j]=tb[i][j];
    }
    dat[nn-1+i].bd=cnt;
    //out(dat[nn-1+i],1);
  }
  //out(dat[nn-1]+dat[nn-1+1],1); return 0;
  rrep(i,nn-1) dat[i]=dat[i*2+1]+dat[i*2+2];
  //out(dat[0].l,dat[0].r,dat[0].bd,dat[0].cnt,1);
  //out(query(1,5),1);
  rep(i,q){
    int l,r;
    //l=0; r=m;
    cin>>l>>r; --l;
    Seg tmp;
    query(tmp,l,r);
    cout<<tmp.cnt+tmp.bd<<endl;
  }
  return 0;
}