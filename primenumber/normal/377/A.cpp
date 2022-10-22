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

int sh(vector<string>& mp,int n,int m,int i,int j,int l){
  int di[4]={1,0,-1,0};
  int dj[4]={0,1,0,-1};
  if(l<=0)return 0;
  mp[i][j]='.';
  --l;
  int cnt=1;
  if(l<=0)return 1;
  REP(k,4){
    int ni=i+di[k];
    int nj=j+dj[k];
    if(ni<0||ni>=n||nj<0||nj>=m)continue;
    if(mp[ni][nj]=='X'){
      int num = sh(mp,n,m,ni,nj,l);
      cnt += num;
      l -= num;
    }
  }
  return cnt;
}

int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  vector<string> mp(n);
  int cnt=0;
  int ei=0,ej=0;
  REP(i,n){
    cin>>mp[i];
    REP(j,m){
      if(mp[i][j]=='.'){
        ++cnt;
        mp[i][j]='X';
        ei=i;ej=j;
      }
    }
  }
  sh(mp,n,m,ei,ej,cnt-k);
  REP(i,n)cout<<mp[i]<<endl;
  return 0;
}