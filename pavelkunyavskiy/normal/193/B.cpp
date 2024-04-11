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

int a[35][35];
int b[35];
int k[35];
int p[35];
int n,u,r;  
int temp[35];

ll ans;


void go(int pos,int last){
    if (pos%2 == u%2){
        ll cur = 0;
        for (int i = 0; i < n; i++){
            cur += a[pos][i]*1LL*k[i];
        }
        ans = max(ans,cur);
    }
    if (pos == u)
        return;

    for (int i = 0; i < n; i++){
        a[pos+1][i] = a[pos][p[i]]+r;
    }
    go(pos+1,1);
    if (last){
        for (int i = 0; i < n; i++)
            a[pos+1][i] = a[pos][i] ^ b[i];
        go(pos+1,0);
    }
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  ans = -(1LL<<60);

  scanf("%d %d %d",&n,&u,&r);
  for (int i = 0; i < n; i++)
    scanf("%d",&a[0][i]);
  for (int i = 0; i < n; i++)
    scanf("%d",&b[i]);
  for (int i = 0; i < n; i++)
    scanf("%d",&k[i]);
  for (int i = 0; i < n; i++)
    scanf("%d",&p[i]),--p[i];
  
  go(0,1);

  cout << ans << endl;

  return 0;
}