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
void Modinvs(vector<ll> &re,int n){
  re.resize(n+1); re[1]=1;
  for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i)%MOD;
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<ll> v(n),inv;
  Modinvs(inv,1123456);
  rep(i,n)
    cin>>v[i];
  ll re=1,sum=v[0];
  for(int i=1;i<n;++i){
    ll prod=1;
    rep(j,v[i]-1)
      (prod*=sum+v[i]-1-j)%=MOD;
    rep(j,v[i]-1)
      (prod*=inv[j+1])%=MOD;
    //cout<<prod<<endl;
    (re*=prod)%=MOD;
    sum+=v[i];
  }
  cout<<re<<endl;
  return 0;
}