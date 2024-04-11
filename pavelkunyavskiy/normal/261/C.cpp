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



ll ans[2][50];
ll ans2[2][50];




int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  ll n,t;
  cin >> n >> t;

  if (t & (t-1)){
  	printf("%d\n",0);
  	return 0;
  }

  n++;
  int cnt = __builtin_ctzll(t)+1;

  ans[0][0] = 1;

  for (int i = 60; i >= 0; i--){
  	for (int j = 0; j < 45; j++){
  		ans2[1][j] += ans[1][j];
  		ans2[1][j+1] += ans[1][j];
  		if (n & (1LL<<i)) {
  			ans2[0][j+1] += ans[0][j];
  			ans2[1][j] += ans[0][j];
  		} else {
  			ans2[0][j] += ans[0][j];
  		}
  	}                                                                            
  	memcpy(ans,ans2,sizeof(ans));
  	memset(ans2,0,sizeof(ans));  	
  	//cerr << ans[0][0] <<" "<<ans[0][1] <<" "<<ans[1][0] <<" "<<ans[1][1] << endl;
  }


  cout << (ans[0][cnt] + ans[1][cnt]) - (t == 1) << endl;
  return 0;
}