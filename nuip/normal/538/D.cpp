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
int n;
bool isval(int x,int y){
  return 0<=x && x<n && 0<=y && y<n;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  cin>>n;
  vector<string> in(n),re(2*n-1,string(2*n-1,'.'));
  rep(i,n)
    cin>>in[i];
  re[n-1][n-1]='o';
  rep(i,2*n-1)rep(j,2*n-1){
    int dy=i-n+1,dx=j-n+1;
    if(!dy && !dx)continue;
    int f=1;
    rep(y,n)rep(x,n)
      if(in[y][x]=='o' && isval(x+dx,y+dy)){
	if(in[y+dy][x+dx]=='.')
	  f=0;
      }
    if(f)
      re[i][j]='x';
    }
  //check
  vector<string> tmp(n,string(n,'.'));
  rep(y,n)rep(x,n)if(in[y][x]=='o'){
    tmp[y][x]='o';
    rep(i,2*n-1)rep(j,2*n-1){
      int dy=i-n+1,dx=j-n+1;
      if(isval(x+dx,y+dy)&&re[i][j]=='x')
	if(tmp[y+dy][x+dx]!='o')
	  tmp[y+dy][x+dx]='x';
    }
  }//cout<<re<<tmp;
   /* rep(i,2*n-1)
      cout<<re[i]<<endl;
    rep(i,n)
    cout<<tmp[i]<<endl;*/
  if(in==tmp){
    cout<<"YES"<<endl;
    rep(i,2*n-1)
      cout<<re[i]<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}