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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<int> a(n),cnt(m);
  vv<int> inv(n+1);
  rep(i,n) cin>>a[i];
  ll x,y,ng=0,re=0;
  rep(i,m){
    cin>>x>>y;
    inv[x].pb(i);
    inv[y].pb(i);
  }
  for(int l=0,r=0;l<n;++l){
    r=max(l,r);
    while(!ng){
      if(r>=n) break;
      for(int t:inv[a[r]])
	if(++cnt[t]==2) ++ng;
      ++r;
    }
    re+=max(0,r-l-!!ng);
    //cout<<pii(l,r)<<ng<<cnt;
    if(l<r)
      for(int t:inv[a[l]])
	if(cnt[t]--==2) --ng;
  }
  cout<<re<<endl;
  return 0;
}