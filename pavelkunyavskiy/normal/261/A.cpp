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


int a[110000];
int b[110000];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  	int m,n;
  	scanf("%d",&m);
  	for (int i = 0; i < m; i++)
  		scanf("%d",&a[i]);
  	scanf("%d",&n);
  	for (int i = 0; i < n; i++)
  		scanf("%d",&b[i]);

  	int q = *min_element(a,a+m);

  	sort(b,b+n,greater<int>());

  	ll ans = 0;

  	for (int i = 0; i < n; i++){
  		if (i % (q+2) != q && i % (q+2) != q+1)
  			ans += b[i];
  	}

  	cout << ans << endl;      
    return 0;
}