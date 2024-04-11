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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  ll c,ha,hb,wa,wb;
  cin>>c>>ha>>hb>>wa>>wb;
  if(wa>wb){
    swap(wa,wb);
    swap(ha,hb);
  }
  ll sq=10000,re=0;
  if(wb<sq){
    if(ha*wb>hb*wa){
      swap(wa,wb);
      swap(ha,hb);
    } //cout<<ha<<","<<wb<<endl;
    rep(i,wb){
      if(c<i*wa)break;
      //cout<<i<<":"<<i*ha+(c-i*wa)/wb*hb<<endl;
      re=max(re,i*ha+(c-i*wa)/wb*hb);
    }
  }else{
    rep(i,c/wb+1){
      re=max(re,i*hb+(c-i*wb)/wa*ha);
    }
  }
  cout<<re<<endl;
  return 0;
}