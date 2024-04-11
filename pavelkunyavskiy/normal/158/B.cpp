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

int cnt[10];
int n;

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int ans = 0;

  scanf("%d",&n);

  for (int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    if (x == 4)
        ans++;
    else
        cnt[x]++;
  }

  ans += max((cnt[1]+cnt[2]*2+cnt[3]*3+3)/4,(cnt[2]+1)/2+cnt[3]);

  cout << ans << endl;          
  return 0;
}