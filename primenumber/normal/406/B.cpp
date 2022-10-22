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
  int n;
  scanf("%d",&n);
  vecint v(1000000,0);
  REP(i,n){
    int xi;
    scanf("%d",&xi);
    xi--;
    v[xi]=-1;
  }
  set<int> m;
  queue<int> emp;
  REP(i,500000){
    if(v[i]!=-1 && v[999999-i] != -1){
      emp.push(i);
    }
  }
  REP(i,1000000){
    if(v[i]==-1){
      if(v[999999-i]==-1){
        if (i < 999999-i) {
          int e = emp.front();emp.pop();
          m.insert(e);
          m.insert(999999-e);
        }
      } else {
        m.insert(999999-i);
      }
    }
  }
  printf("%d\n", m.size());
  for(auto itr=m.begin();itr != m.end();++itr){
    if(itr!=begin(m))
      printf(" ");
    printf("%d",*itr+1);
  }
  return 0;
}