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

const int MAXN = 210000;

int a[MAXN];
int b[MAXN];


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n;
  scanf("%d",&n);

  for (int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    a[x] = i;
  }

  int cnt = 0;

  for (int i = 0; i < n; i++){
    scanf("%d",&b[i]);
    b[i] = a[b[i]];
    if (b[i] == cnt)
        cnt++;
  }

  cout << n - cnt << endl;

  return 0;
}