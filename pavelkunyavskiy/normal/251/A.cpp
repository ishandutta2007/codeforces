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

int n,d;

int a[110000];


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&d);

    for (int i = 0; i < n; i++)
    	scanf("%d",&a[i]);

    ll ans = 0;

    int ptr = 0;

    for (int i = 0; i < n; i++){
    	while (ptr < n && a[ptr] - a[i] <= d)
    		ptr++;
    	int len = ptr - i;
    	if (len) ans += (len - 1) * 1LL * (len - 2)/2;
    }

    cout << ans << endl;

      
  return 0;
}