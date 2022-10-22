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

int main()
{
  int n,m;
  cin>>n>>m;
  string s,sb;
  if(n==m+1){
    s+='0';
    n--;
  }
  if(n*2<m&&n*2+2>=m){
    sb+=string(m-n*2,'1');
    m -= m-n*2;
  }
  if(n>m||n*2<m){
    cout<<"-1"<<endl;
  }else{
    while(n<m){
      s+="110";
      n-=1;
      m-=2;
    }
    while(n||m){
      s+="10";
      n--;m--;
    }
    cout<<s<<sb<<endl;
  }
  
  return 0;
}