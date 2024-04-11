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

vector<ll> fact;

vector<int> dfs(ll n,ll t){
  if(n==1) return vector<int>(1,0);
  if(n==2) return {1-(int)t,(int)t};
  vector<int> re;
  if(t<fact[n-1]){
    re=dfs(n-1,t);
    for(int &a:re)
      ++a;
    re.pb(0);
  }else{
    re=dfs(n-2,t-fact[n-1]);
    for(int &a:re)
      a+=2;
    re.pb(0); re.pb(1);
  }
  //cout<<n<<","<<t<<re;
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  ll n,t;
  cin>>n>>t; --t;
  fact.resize(2,1);
  while(fact.back()<=t){
    fact.pb(fact.back()+fact[fact.size()-2]);
    if(fact.back()<fact[fact.size()-2]){
      fact.back()=1e18+2;
      break;
    }
  }
  while(fact.size()<=n)
    fact.pb(1e18+3);
  //cout<<fact;
  vector<int> re=dfs(n,t);
  //cout<<re;
  rrep(i,n)
    cout<<re[i]+1<<" ";
  cout<<endl;
  return 0;
}