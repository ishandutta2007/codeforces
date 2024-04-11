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
inline bool fight(multiset<ll> &st,ll pw){
  if(st.empty()) return 0;
  auto it=st.upper_bound(pw);
  if(it!=st.begin()){
    --it;
    st.erase(it);
    return 1;
  }
  return 0;
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<ll> p(3);
  multiset<ll> st;
  rep(i,3) cin>>p[i];
  int x;
  int re=0;
  ll sum=accumulate(all(p),0ll);
  sort(all(p));
  rep(i,n){
    cin>>x;
    if(x>sum-p[0]){
      if(x>sum){
	cout<<-1<<endl;
	return 0;
      }
      ++re;
    }else{
      st.insert(x);
    }
  }
  vector<ll> gt={p[0]+p[2],max(p[2],p[0]+p[1]),p[2]},fr={p[0],p[1],p[2]};
  //cout<<st.size()<<endl;
  rep(i,3){
    while(st.size() && *st.rbegin() > gt[i]){
      ++re;
      auto it=st.end(); --it;
      st.erase(it);
      if(st.empty()) break;
      fight(st,fr[i]);
    }
  }
  //cout<<st.size()<<endl;
  //for(ll x:st)cout<<x<<",";cout<<endl;
  int cnt=0;
  while(st.size()){
    ++cnt;
    fight(st,p[2]);
    int a=fight(st,p[0]);
    fight(st,p[0]*(1-a)+p[1]);
  }
  //cout<<re<<","<<cnt<<endl;
  cout<<re+cnt<<endl;
  return 0;
}