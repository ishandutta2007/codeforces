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


int p[2100];
int d[2100];

int calc(int v){
    if (d[v] != -1)
        return d[v];
    if (p[v] == -1)
        return 1;
    return d[v] = calc(p[v])+1;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    scanf("%d",&p[i]);
    if (p[i] > 0)
        --p[i];
  }
  memset(d,-1,sizeof(d));

  int ans = 1;

  for (int i = 0; i < n; i++)
    ans = max(ans,calc(i));

  cout << ans << endl;
  return 0;
}