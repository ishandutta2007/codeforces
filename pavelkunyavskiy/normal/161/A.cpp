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


const int MAXN = 110000;

int n,m;
int x,y;

pair<int,int> a[MAXN];
pair<int,int> b[MAXN];


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d %d %d",&n,&m,&x,&y);
  for (int i = 0; i < n; i++){
    scanf("%d",&a[i].first);
    a[i].first -= x;
    a[i].second = i;
  }
  ll len = x+y;
  for (int j = 0; j < m; j++){
    scanf("%d",&b[j].first);
    b[j].second = j;
  }

  sort(a,a+n);
  sort(b,b+m);

  int ptr;
  ptr =  0;

  vector<pair<int,int> > res;

  for (int i = 0; i < m; i++){
    while (ptr < n && a[ptr].first+len < b[i].first)
        ptr++;
    if (ptr == n)
        break;
    if (a[ptr].first <= b[i].first){
        res.pb(mp(a[ptr].second,b[i].second));
        ptr++;
    }
  }

  printf("%d\n",res.size());
  for (int i = 0; i < (int)res.size(); i++)
    printf("%d %d\n",res[i].first+1,res[i].second+1);

  return 0;
}