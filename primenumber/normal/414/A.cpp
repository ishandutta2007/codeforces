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
  int n,k;
  cin>>n>>k;
  if (n/2 > k || (n < 2 && k > 0)) {
    cout<<"-1"<<endl;
  } else {
    REP(i,n/2-1){
      if(i)cout<<' ';
      cout<<(i*2+1)<<' '<<(i*2+2);
    }
    int rem = k-n/2+1;
    int r=rem - ((n/2-1)*2)%rem;
    if(n/2>=2)cout<<' ';
    if(n/2>=1)cout<<(n/2-1)*2+r<<' '<<(n/2-1)*2+r+rem;
    if(n%2==1){
      if(n>1)cout<<' ';
      cout<<n+r+rem;
    }
    cout<<endl;
  }
  return 0;
}