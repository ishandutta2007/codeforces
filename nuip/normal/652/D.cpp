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
const int nn=412345;
ll bit[nn+1];

ll sum(int i){
  i=nn-i-10;
  ll s=0;
  while(i>0){
    s+=bit[i];//ok?
    i-=i&-i;
  }
  return s;
}

void add(int i,int x){
  i=nn-i-10;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<pii> ps,ls;
  int x,y;
  vector<int> zip;
  rep(i,n){
    cin>>x>>y;
    zip.pb(x); zip.pb(y);
    ps.eb(x,y);
    ls.eb(y,i);
  }
  sort(all(zip));
  for(pii &p:ps){
    p.X=lower_bound(all(zip),p.X)-zip.begin();
    p.Y=lower_bound(all(zip),p.Y)-zip.begin();
  }
  for(pii &p:ls)
    p.X=lower_bound(all(zip),p.X)-zip.begin();
  sort(all(ls));
  set<int> st;
  vector<int> re(n);
  for(pii p:ls){
    re[p.Y]=sum(ps[p.Y].X);
    add(ps[p.Y].X,1);
  }
  rep(i,n) cout<<re[i]<<endl;
  return 0;
}