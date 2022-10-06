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

double dif[5123],dp[5123];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  sort(all(a));
  rep(i,n)rep(j,i){
    int d=a[i]-a[j];
    if(d<=5000) dif[d]+=1;
  }
  rep(i,5120)rep(j,5120-i) dp[i+j]+=dif[i]*dif[j];
  rep(i,5120) dp[i+1]+=dp[i];
  double re=0;
  rep(i,n)rep(j,i){
    int d=a[i]-a[j];
    if(d<=5000) re+=dp[d-1];
  }
  //cout<<re<<endl;
  rep(i,3) re/=1ll*n*(n-1)/2;
  cout<<re<<endl;
  return 0;
}