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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<pii> lc(n);
  rep(i,n)
    cin>>lc[i].X;
  rep(i,n)
    cin>>lc[i].Y;
  sort(all(lc));
  lc.eb(1e6,-1);
  int sum=0;
  rep(i,n) sum+=lc[i].Y;
  vector<int> cnt(210);
  int l=0,r=0,s=0,re=1e9,lsum=0;
  rep(i,100045){
    while(lc[l].X<i){
      ++cnt[lc[l].Y];
      ++l;
    }
    s=0;
    while(lc[r].X<=i){
      s+=lc[r].Y;
      ++r;    
    }
    int num=0,add=0;
    //if(i<10)cout<<pii(l,r)<<lsum<<","<<num<<endl;
    rep(j,205){
      if(l-num-cnt[j]<r-l){
	add+=(-r+l+l+1-num)*j;
	//cout<<l<<","<<r<<","<<lsum<<","<<num<<","<<cnt[j]<<endl;
	break;
      }
      num+=cnt[j];
      add+=cnt[j]*j;
    }
    //if(i<10)cout<<add<<","<<sum-lsum-s<<endl;
    re=min(re,add+sum-lsum-s);
    lsum+=s;
  }
  cout<<re<<endl;
  return 0;
}