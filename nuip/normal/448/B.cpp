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
//--
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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
  int i,j,k;
  string s,t,ss,tt;
  cin>>s>>t;
  ss=s,tt=t;
  rep(i,t.size()){
    bool f=0;
    rep(j,s.size()){
      if(tt[i]==ss[j]){
        ss[j]='.';
        f=1;
        break;
      }
    }
    if(f==0){
      cout<<"need tree"<<endl;
      return 0;
    }
  }
  if(s.size()==t.size()){
    cout<<"array"<<endl;
    return 0;
  }
  ss=s,tt=t;
  rep(i,t.size()){
    bool f=0;
    rep(j,s.size()){
      if(tt[i]==ss[j]){
        f=1;
      ss[j]='.';
        break;
      }
      ss[j]='.';
    }
    if(f==0){
      cout<<"both"<<endl;
      return 0;
    }
  }
//      cout<<ss<<endl<<tt<<endl;
  cout<<"automaton"<<endl;
  
  return 0;
}