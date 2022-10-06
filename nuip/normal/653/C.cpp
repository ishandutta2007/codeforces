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

int ok2(const vector<int> &a,int i){
  
    if(i%2){
      if(a[i]<=a[i+1]) return 0;
    }else{
      if(a[i]>=a[i+1]) return 0;
    }
    return 1;
}
int ok(const vector<int> &a,int i){
  if(i+1<a.size() && !ok2(a,i)) return 0;
  if(i && !ok2(a,i-1))return 0;
  return 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  vector<int> ng;
  rep(i,n-1){
    if(!ok(a,i)) ng.pb(i);
  }

  if(ng.size()>6){
    cout<<0<<endl;
    return 0;
  }

  vector<int> cand;
  for(int x:ng) rep(j,3) cand.pb(max(0,min(n-1,x+j-1)));
  sort(all(cand));
  UNIQUE(cand);
  //cout<<ng<<cand;
  set<pii> re;
  for(int i:cand){
    rep(j,n)if(i!=j){
      swap(a[i],a[j]);
      int f=1;
      if(!ok(a,i) || !ok(a,j)) f=0;
      if(f)for(int x:ng)if(!ok(a,x)){
	    f=0;
	    break;
	  }
      //cout<<pii(i,j)<<f<<a;
      if(f){
	if(i<j)
	  re.emplace(i,j);
	else
	  re.emplace(j,i);
      }
      swap(a[i],a[j]);      
    }
  }
  cout<<re.size()<<endl;
  return 0;
}