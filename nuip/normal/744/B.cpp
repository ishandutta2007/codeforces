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

int n;

vector<int> ask(vector<int> &v){
  cout<<v.size()<<endl;
  rep(i,v.size()){
    if(i) cout<<" ";
    cout<<v[i]+1;
  }
  cout<<endl<<flush;
  vector<int> re(n);
  rep(i,n) cin>>re[i], --re[i];
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin>>n;
  vector<int> re(n,MOD);
  rep(i,10){
    vector<int> v,w;
    rep(j,n) (j>>i&1?v:w).pb(j);
    if(v.size()==0 || w.size()==0) continue;
    vector<int> ansv=ask(v);
    vector<int> answ=ask(w);
    rep(j,n) MN(re[j],(j>>i&1?answ[j]:ansv[j]));
  }
  cout<<-1<<endl<<flush;
  rep(i,n){
    if(i) cout<<" ";
    cout<<re[i]+1;
  }
  cout<<endl<<flush;
  return 0;
}