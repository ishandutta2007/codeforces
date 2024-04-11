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
const ll MOD=1e9+7;

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
typedef pair<pii,int> piii;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  UF uf(n);
  vector<pii> fre,re(m);
  rep(i,n)rep(j,i-1){
    fre.eb(i,j);
    if(fre.size()>m) break;
  }
  reverse(all(fre));
  vector<piii> ps(m);
  set<pii> used;
  rep(i,m){
    cin>>ps[i].X.X>>ps[i].X.Y;
    ps[i].X.Y*=-1;
    ps[i].Y=i;
  }
  sort(all(ps));
  //cout<<fre;
  int cnt=0;
  int f=1;
  for(piii p:ps){
    if(p.X.Y){
      re[p.Y]=pii(cnt,1+cnt);
      ++cnt;
    }else{
      if(fre.size() && fre.back().X<=cnt){
	re[p.Y]=fre.back();
	fre.pop_back();
      }else{
	f=0;
      }
    }
  }
  if(f){
    rep(i,m)
      cout<<re[i].X+1<<" "<<re[i].Y+1<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}