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

int dp[212][212][212];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  string str;
  cin>>n>>str;
  vector<int> cnt(200);
  for(char c:str) ++cnt[c];
  dp[cnt['R']][cnt['G']][cnt['B']]=1;
  rrep(len,n+1){
      rep(r,len+1) rep(g,len+1-r){
    int b=len-r-g;
    if(!dp[r][g][b]) continue;
    if(r>1) dp[r-1][g][b]=1;
    if(g>1) dp[r][g-1][b]=1;
    if(b>1) dp[r][g][b-1]=1;
    if(min(r,g)) dp[r-1][g-1][b+1]=1;
    if(min(g,b)) dp[r+1][g-1][b-1]=1;
    if(min(r,b)) dp[r-1][g+1][b-1]=1;
      }
      //rep(i,n+1){rep(j,n+1){rep(k,n+1)cout<<dp[i][j][k]<<",";cout<<endl;}cout<<endl;}
  }
  if(dp[0][0][1])cout<<"B";
  if(dp[0][1][0])cout<<"G";
  if(dp[1][0][0])cout<<"R";
  cout<<endl;
  return 0;
}