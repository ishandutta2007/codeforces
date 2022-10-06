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
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
  os<<"{"; for(auto i:t) {os<<i<<",";} os<<"}"<<endl; return os;}
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

ll MOD=1e9+9;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k,n;
  cin>>n;
  vector<ll> sta(n),pw(n);
  vector<pii> cubes(n);
  map<ll,int> y[n+10];
  pw[0]=1;
  rep(i,n-1)
    pw[i+1]=pw[i]*n%MOD;
  rep(i,n){
    cin>>cubes[i].X>>cubes[i].Y;
    y[cubes[i].Y][cubes[i].X]=i;
  }
  rep(i,n){
    if(cubes[i].Y){
      rep(j,3)
	sta[i]+=y[cubes[i].Y-1].count(cubes[i].X-1+j);
    }else{
      sta[i]=10;
    }
  }
  set<int> ok;
  rep(i,n){
    int f=0;
    rep(j,3){
      if(y[cubes[i].Y+1].count(cubes[i].X-1+j))
	f|=(sta[y[cubes[i].Y+1][cubes[i].X-1+j]]==1);
    }
    if(!f)
      ok.insert(i);
  }
  ll re=0,rm;
  rep(i,n){
    if(i%2){
      rm=*ok.begin();
    }else{
      rm=*ok.rbegin();
    }
    //    cout<<ok<<rm<<endl;
    (re+=rm*pw[n-1-i]%MOD)%=MOD;
    y[cubes[rm].Y].erase(cubes[rm].X);
    ok.erase(rm);
    rep(j,3){
      if(y[cubes[rm].Y+1].count(cubes[rm].X-1+j)){
	int up=y[cubes[rm].Y+1][cubes[rm].X-1+j];
	if(--sta[up] == 1){
	  rep(k,3)if(y[cubes[rm].Y].count(cubes[up].X-1+k))
	    ok.erase(y[cubes[rm].Y][cubes[up].X-1+k]);
	}
      }
      if(cubes[rm].Y && y[cubes[rm].Y-1].count(cubes[rm].X-1+j)){
	int f=0,dwn=y[cubes[rm].Y-1][cubes[rm].X-1+j];
	rep(k,3){
	  if(y[cubes[dwn].Y+1].count(cubes[dwn].X-1+k))
	    f|=sta[y[cubes[dwn].Y+1][cubes[dwn].X-1+k]]==1;
	}
	if(!f)
	  ok.insert(dwn);
      }
    }
  }
  cout<<re<<endl;
  return 0;
}