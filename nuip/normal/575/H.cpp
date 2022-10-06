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

vector<ll> fact,finv,inv;
void Modinvs(vector<ll> &re,int n){
  re.resize(n+1); re[1]=1;
  for(int i=2;i<=n;++i)re[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
}
void Facts(vector<ll> &re,int n){
  re.resize(n+1); re[0]=1;
  rep(i,n)re[i+1]=re[i]*(i+1)%MOD;
}
void Factinvs(vector<ll> &re,const vector<ll> &inv,int n){
  re.resize(n+1); re[0]=1;
  rep(i,n)re[i+1]=re[i]*inv[i+1]%MOD;
}
ll comb(ll n,ll r){
  if(n<r||r<0)return 0;
  return fact[n]*finv[n-r]%MOD*finv[r]%MOD;
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  Modinvs(inv,2123456);
  Facts(fact,2123456);
  Factinvs(finv,inv,2123456);
  int n;
  cin>>n;
  ll re=0,x=comb(2*n,n),div2=finv[2];
  //cout<<x<<endl;
  rrep(i,2*n){
    (re+=x)%=MOD;
    int a=2*comb(i,i-n)%MOD;
    //cout<<i<<":"<<a<<endl;
    x=((x-a)*div2+a)%MOD;
    (x+=MOD)%=MOD;
    //cout<<x<<endl;
  }
  (re+=x)%=MOD;
  (re+=MOD)%=MOD;
  cout<<re<<endl;
  return 0;
}