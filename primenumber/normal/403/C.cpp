#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

void fm(vector<vecint>& mt,vecint& from,int n){
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int i=q.front();q.pop();
    REP(j,n){
      if(mt[i][j]!=0&&from[j]==0){
        from[j]=1;
        q.push(j);
      }
    }
  }
}

void to_(vector<vecint>& mt,vecint& to,int n){
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int i=q.front();q.pop();
    REP(j,n){
      if(mt[j][i]!=0&&to[j]==0){
        to[j]=1;
        q.push(j);
      }
    }
  }
}

int main()
{
  int n;cin>>n;
  vector<vecint> mt(n,vecint(n));
  REP(i,n)REP(j,n)scanf("%d",&mt[i][j]);
  vecint from(n,0);
  from[0]=1;
  fm(mt,from,n);
  REP(i,n){
    if(from[i]==0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  vecint to(n,0);
  to[0]=1;
  to_(mt,to,n);
  REP(i,n){
    if(to[i]==0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}