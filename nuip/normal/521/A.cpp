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
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const ll MOD=1e9+7;

ll modpow(ll r,ll n,ll m=MOD){
  if(n<0)return modpow(modpow(r,-n,m),m-2);
  if(n==0)return 1ll;
  ll tmp=modpow(r,n/2,m);
  return tmp*tmp%m*(n%2?r:1ll)%m;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n;
  string str;
  cin>>n>>str;
  vector<int> v(26);
  rep(i,n){
    v[str[i]-'A']++;
  }
  sort(rall(v));
  int m=0;
  rep(i,26)
    if(v[0]==v[i])
      ++m;
  // cout<<v<<m<<endl;
  cout<<modpow(m,n)<<endl;
  return 0;
}