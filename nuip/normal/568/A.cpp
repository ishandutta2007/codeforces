
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

const int PRIME_MAX=11234567;
vector<int> primes;
int prime[PRIME_MAX],pi[PRIME_MAX],pal[PRIME_MAX];
void findPrime(){
  for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
      primes.pb(i);
      for(int j=i*2;j<PRIME_MAX;j+=i)
	prime[j]=1;
  }
}

int rev(int n){
  int re=0;
  for(;n;n/=10){
    re*=10;
    re+=n%10;
  }
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  findPrime();
  rep(i,PRIME_MAX-1){
    pal[i+1]=pal[i]+(i+1==rev(i+1));
    pi[i+1]=pi[i]+(prime[i+1]==0 && i>0);
  }
  //rep(i,50)if(i)cout<<i<<":"<<pi[i]<<","<<pal[i]<<endl;
  ll p,q;
  cin>>p>>q;
  int re=0;
  rep(i,PRIME_MAX){
    if(q*pi[i]<=p*pal[i])
      re=i;
  }
  cout<<re<<endl;
  return 0;
}