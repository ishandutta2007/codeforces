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

vector<string> mp(3);
int n,m,tab[3][3]={{1,1,0},{1,1,1},{0,1,1}};
bool solve(){
  rep(i,3) mp[i]+="........";
  vector<int> ok[2];
  rep(i,2) ok[i].resize(3);
  rep(i,3){
    if(mp[i][0]!='s')continue;
    ok[0][i]=1;
    if(mp[i][1]!='.') return 0;
  }
  
  rep(i,n/3+1){
    fill(all(ok[1-i%2]),0);
    rep(j,3) if(ok[i%2][j]) rep(k,3)
      if(tab[j][k] && mp[k].substr(1+3*i,4)=="....")
	ok[1-i%2][k]=1;
    //cout<<i<<mp[1].substr(1+3*i,4)<<ok[1-i%2];
  }
  rep(i,3) if(ok[(n/3+1)%2][i]) return 1;
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    rep(i,3)
      cin>>mp[i];
    cout<<(solve()?"YES":"NO")<<endl;
  }
  return 0;
}