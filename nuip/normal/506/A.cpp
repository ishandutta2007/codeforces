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

int dp[612][31234],INF=1e7,mp[31234];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,d;
  fill(dp[0],dp[0]+612*31234,-INF);
  cin>>n>>d;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
    mp[a[i]]++;
  }
  int re=0,t=305-d;
  dp[t+d][0]=0;
  rep(i,30000+1)
    for(int dd=d-300;dd<=d+300;++dd){//cout<<dd<<endl;
      dp[t+dd][i]+=mp[i];
      re=max(re,dp[t+dd][i]);
      rep(j,3)
	dp[t+max(1,dd-1+j)][i+dd]=
	max(dp[t+max(1,dd-1+j)][i+dd],dp[t+dd][i]);
    }
  cout<<re<<endl;
  return 0;
}