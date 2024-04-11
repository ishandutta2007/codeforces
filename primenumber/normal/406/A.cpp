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
  int sum=0;
  REP(i,n){
    REP(j,n){
      int a;
      scanf("%d",&a);
      if(i==j){
        sum+=a;
        sum%=2;
      }
    }
  }
  int q;
  scanf("%d",&q);
  REP(i,q){
    int c,o;
    scanf("%d",&c);
    switch(c){
      case 1:
      case 2:
      scanf("%d",&o);
      sum++;
      sum%=2;
      break;
      case 3:
      printf("%d",sum);
      break;
    }
  }
  printf("\n");
  return 0;
}