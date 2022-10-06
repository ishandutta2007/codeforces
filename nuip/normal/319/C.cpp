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

inline bool ok(double a1,double a2,double a3,double b1,double b2,double b3){
  return (a2-a1)*(b3-b2)<=(a3-a2)*(b2-b1);
}

void out(deque<int> que){
  cout<<"{";
  while(que.size()){
    cout<<que.front()<<",";que.pop_front();
  }
  cout<<"}"<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<ll> h(n),a(n),dp(n);
  rep(i,n) cin>>h[i];
  rep(i,n) cin>>a[i];
  deque<int> que;
  que.pb(0);
  rep(i,n)if(i){
    while(que.size()>=2){
      int x=que[0],y=que[1];
      if(a[x]*h[i]+dp[x] <= a[y]*h[i]+dp[y])
	break;
      que.pop_front();
    }
    //out(que);
    dp[i]=a[que.front()]*h[i]+dp[que.front()];
    while(que.size()>=2){
      int m=que.size();
      if(ok(a[que[m-2]], a[que[m-1]], a[i], 
	    dp[que[m-2]], dp[que[m-1]], dp[i])) break; 
      que.pop_back();
    }
    que.pb(i);
  }
  //cout<<dp;
  cout<<dp[n-1]<<endl;
  return 0;
}