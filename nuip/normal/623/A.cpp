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

int g[512][512],d[512];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  int x,y;
  fill(g[0],g[0]+512*512,1);
  rep(i,m){
    cin>>x>>y; --x; --y;
    g[x][y]=g[y][x]=0;
  }
  fill(d,d+512,MOD);
  queue<int> que;
  rep(i,n) if(accumulate(g[i],g[i]+n,0)!=1){
    d[i]=0;
    que.push(i);
    break;
  }
  while(que.size()){
    int t=que.front(); que.pop();
    rep(i,n) if(d[i]==MOD && g[t][i]){
      d[i]=d[t]+1;
      que.push(i);
    }
  }
  int f=0;
  //rep(i,n){rep(j,n) cout<<g[i][j];cout<<endl;}
  //rep(i,n) cout<<d[i]<<",";cout<<endl;
  rep(i,n){
    if(d[i]==MOD){
      if(accumulate(g[i],g[i]+n,0)!=1) f=1;
    }else{
      rep(j,n)if(d[j]!=MOD){
	if(i!=j && g[i][j] && d[i]%2==d[j]%2) f=1;
	if(i!=j && !g[i][j] && d[i]%2!=d[j]%2) f=1;
      }
    }
  }
  if(f){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  rep(i,n){
    if(d[i]==MOD){
      cout<<"b";
    }else{
      cout<<(d[i]%2?"c":"a");
    }
  }
  cout<<endl;
  return 0;
}