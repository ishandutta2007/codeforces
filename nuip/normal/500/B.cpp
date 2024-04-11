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
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

vector<string>  A(312);
int used[312],n;
vector<vector<int>> cc;

void dfs(int p){
  if(used[p])return;
  used[p]=1;
  cc.back().pb(p);
  rep(i,n)
    if(A[p][i]=='1')dfs(i);
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  cin>>n;
  vector<int> p(n);
  rep(i,n)
    cin>>p[i];
  rep(i,n)cin>>A[i];
  rep(i,n){
    if(!used[i]){
      cc.pb(vector<int>());
      dfs(i);
    }
  }
  // cout<<cc;
  rep(i,cc.size()){
    vector<int> st;
    sort(all(cc[i]));
    rep(j,cc[i].size())
      st.pb(p[cc[i][j]]);
    sort(all(st));
    rep(j,cc[i].size())
      p[cc[i][j]]=st[j];
  }
  rep(i,n)
    cout<<p[i]<<" ";cout<<endl;
  return 0;
}