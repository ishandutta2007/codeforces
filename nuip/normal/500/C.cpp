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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m;
  cin>>n>>m;
  vector<ll> w(n),b(m),sum(n),stk;
  ll re=0;
  rep(i,n)cin>>w[i];
  rep(i,m)cin>>b[i];
  rep(i,m){
    b[i]--;
    if(count(all(stk),b[i])==0)
      stk.pb(b[i]);
  }
  rep(i,m){
    //   cout<<b[i]<<endl;
    rep(j,stk.size()){
      if(stk[j]==b[i]){
	stk.erase(stk.begin()+j);
	break;
      }
      re+=w[stk[j]];
    }
    stk.insert(stk.begin(),b[i]);
    //   cout<<stk<<re;
  }
  cout<<re<<endl;
  return 0;
}