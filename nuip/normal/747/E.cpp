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
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

char str[1123456];

vector<string> re[1123456];

void dfs(  vector<pair<string,int>> &ps,int &ind,int dep){
  re[dep].pb(ps[ind].X);
  int t=ps[ind].Y;
  ++ind;
  rep(i,t) dfs(ps,ind,dep+1);
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(0);
  int num=4;
  vector<pair<string,int>> ps;
  while(scanf("%[^,]s",str)){
    getchar();
    scanf("%d",&num);
    ps.eb(str,num);
    if(','!=getchar()) break;
  }
  //cout<<ps.size()<<ps;
  int ind=0;
  while(ind<ps.size()) dfs(ps,ind,0);
  int d=0;
  for(;re[d].size();++d);
  cout<<d<<endl;
  rep(i,d){
    for(string &s:re[i]) cout<<s<<" ";
    cout<<endl;
  }
  return 0;
}