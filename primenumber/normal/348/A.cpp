#include <iostream>
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
  cin>>n;
  vecint a(n);
  REP(i,n)cin>>a[i];
  sort(ALL(a),greater<int>());
  long long sum = 0;
  FOR(i,1,n)sum += a[0]-a[i];
  if(sum >= a[0])
    cout << a[0] << endl;
  else
    cout << ((a[0]-sum-1)/(n-1)+1+a[0]) << endl;
  return 0;
}