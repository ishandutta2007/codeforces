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


long long solve(ll r){
    if (r < 10)
        return r+1;
    ll ans = 10;            
    

    for (ll x = 10; ; x *= 10){
        for (int i = 1; i <= 9; i++){
            if (r >= x*(i+1))
                ans += x/10;
            else {
                ans += (r - x*i - i+10)/10; 
                break;
            }
        }
        if (x > r/10)
            break;
    }
        
    return ans;
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    ll l,r;
    cin >> l >> r;
    //cerr << solve(l-1) <<" "<<solve(r) << endl;
    cout << solve(r) - solve(l-1) << endl; 
      
  return 0;
}