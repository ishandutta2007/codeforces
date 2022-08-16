#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcnt      __builtin_popcnt
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;


const int mxn = 100007;
char a[mxn];
int k, n;

int cnt[26], id[26];
int take[26];

int main(int argc, char** argv) {
    
  scanf("%s", a);
  s(k);
  n = strlen(a);
  for (int i=0; i < n; i++)
    cnt[ a[i] - 'a' ]++;
  for (int i=0; i < 26; i++)
    id[i] = i;
  for (int i=0; i < 26; i++)
  for (int j=i+1; j < 26; j++)
    if (cnt[ id[j] ] > cnt[ id[i] ]) {
      swap(id[i], id[j]);
    }
  int len = n - k;
  int m = 0;
  for (int i=0; i < 26; i++) {
    take[ id[i] ] = min( cnt[ id[i] ], max(0,len) );
    if (take[ id[i] ] > 0)
      m++;
    len -= cnt[ id[i] ];
    //cout << id[i] << " " << take[ id[i] ] << endl;
  }
  printf("%d\n", m);
  for (int i=0; i < n; i++) {
    if (take[ a[i] - 'a' ] > 0) {
      putchar( a[i] );
      take[ a[i] - 'a' ]--;
    }
  }
  puts("");
  
    return 0;
}