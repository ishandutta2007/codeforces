#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  ld S;
  cin >> S;

  vector<pair<int,int> > v(3);

  cin >> v[0].first >> v[1].first >> v[2].first;

  for (int i = 0; i < 3; i++)
    v[i].second = i;

  sort(v.begin(),v.end());

  if (v[2].first == 0){
    printf("0 0 0\n");
    return 0;
  }

  ld x = v[0].first/(ld)v[2].first;
  ld y = v[1].first/(ld)v[2].first;
  ld z = 1;

  ld sum = x+y+z;

  x = x/sum*S;
  y = y/sum*S;
  z = z/sum*S;


  vector<pair<int,ld> > ans;

  ans.pb(mp(v[0].second,x));
  ans.pb(mp(v[1].second,y));
  ans.pb(mp(v[2].second,z));

  sort(ans.begin(),ans.end());

  cout.precision(15);

  cout << fixed << ans[0].second <<" "<<ans[1].second <<" "<<ans[2].second << endl;

    

  

  return 0;
}