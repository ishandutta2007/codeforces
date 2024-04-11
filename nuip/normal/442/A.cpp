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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int toNum(string &str){
  return (str[0]-'A')*5+str[1]-'1';
}

int solve(int a,int b,vector<int> &v){
  vector<int> id(256*5,0),used(1000);
  string str="RGBYW";
  rep(i,5)
    if(a&(1<<i))
      rep(j,5)
        id[(str[i]-'A')*5+j]+=i+1;
  rep(i,5)
    if(b&(1<<i))
      rep(j,5)
        id[(str[j]-'A')*5+i]+=(i+1)*7;
  rep(i,v.size()){
    if(used[id[v[i]]])
      return 0;
    used[id[v[i]]]=1;
  }
  if(0&& __builtin_popcount(a)+__builtin_popcount(b)==2){
   cout<<a<<","<<b<<endl;
    rep(i,v.size())
      cout<<id[v[i]]<<",";cout<<endl;
  }
  return 1;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  int n;
  cin>>n;
  vector<int> v;
  string str;
  rep(i,n){
    cin>>str;
 //   cout<<str<<","<<toNum(str)<<endl;
    v.pb(toNum(str));
  }
  sort(all(v));
  v.erase(unique(all(v)),v.end());
//  rep(i,v.size()) cout<<v[i]<<",";cout<<endl;
  int re=16;
  rep(i,1<<5)
    rep(j,1<<5)
      if(solve(i,j,v))
        re=min(re,__builtin_popcount(i)+__builtin_popcount(j));
  cout<<re<<endl;
  return 0;
}