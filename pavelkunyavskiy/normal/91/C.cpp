#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cassert>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
  #define LLD "%lld"
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define LLD "%I64d"
  #define eprintf(...) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;


int p   [110000];
int rank[110000];
int cnt;
int n;

void init(){
  for (int i=0;i<n;i++){
    p[i] = i;
    rank[i] = 1;
  }
  cnt = n;
}

int root(int a){
  if (p[a] == a)
    return a;
  return p[a] = root(p[a]);
}

void join(int a,int b){
  a = root(a);
  b = root(b);
  if (a == b)
    return;
 // cerr << a << " "<<b<<endl;
  --cnt;
  if (rank[a] < rank[b])
    p[a] = b;
  else {
    p[b] = a;
    if (rank[a] == rank[b])
      rank[a]++;
  }
}


const int MOD = 1000000009;

int pow(int a,int b){
  if (b == 0)
    return 1;
  if (b&1)
    return (pow(a,b-1)*1LL*a)%MOD;
  int tmp = pow(a,b>>1);
  return (tmp*1LL*tmp)%MOD;
}

void calc(int x){  
 // cerr << x <<endl;
  x = pow(2,x);
  x = x-1;
  if (x < 0)
    x += MOD;
  printf("%d\n",x);
}

int main(){
  #ifdef LOCAL  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int m;
    scanf("%d %d",&n,&m);
    init();
    for (int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      --a,--b;
      join(a,b);
     // cerr<<"!!!!!!"<<endl;
      calc(i-n+cnt+1);
     // cerr<<"!!!!!!"<<endl;
    }
    return 0;
}