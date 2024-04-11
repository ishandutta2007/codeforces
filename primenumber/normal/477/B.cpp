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

typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main()
{
  int n,k;
  cin>>n>>k;
  set<int> uue;
  REP(i,n) {
    uue.insert(i*6+2);
    uue.insert(i*6+4);
  }
  cout<<(n*6-1)*k<<endl;
  REP(i,n) {
    cout<<(i*6+1)*k<<' '<<(i*6+3)*k<<' '<<(i*6+5)*k<<' ';
    int res=-1;
    for(int e:uue) {
      bool ok = true;
      REP(j,3){
        int x=i*6+j*2+1;
        int y=e;
        if(x<y) swap(x,y);
        if (gcd(x,y) != 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        res=e;
        break;
      }
    }
    cout<<res*k<<endl;
    uue.erase(res);
  }
  return 0;
}