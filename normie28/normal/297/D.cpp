
// Problem : D. Color the Carpet
// Contest : Codeforces - Codeforces Round #180 (Div. 1)
// URL : https://codeforces.com/problemset/problem/297/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
As a tester, contest is bullshit.
abcdefghijklmnopqrstuvwxyz
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
 
constexpr int N = 1000;
 
int h, w, k, tot, res[N][N];
char t[N*2][N*2];
 
int do_row(int i) {
  res[i][0] = 0;
  for(int j = 1, cnt = 1; cnt<w; ++cnt, j+=2) {
    if(t[2*i][j] == 'N')
      res[i][cnt] = 1 - res[i][cnt-1];
    else
      res[i][cnt] = res[i][cnt-1];
  }
  if(i == 0)
    return 0;
  int rtn = 0;
  for(int j = 0, cnt = 0; cnt<w; ++cnt, j+=2) {
    if(t[2*i-1][j] == 'N')
      rtn += (res[i][cnt] != res[i-1][cnt]);
    else
      rtn += (res[i][cnt] == res[i-1][cnt]);
  }
  return rtn;
}
int main() {
  scanf("%d %d %d", &h, &w, &k); getchar();
  tot = 2*h*w - h - w;
  for(int i = 0; i<2*h-1; ++i) {
    for(int j = 1-(i%2), cnt = 0; cnt<(i%2)+w-1; ++cnt, j+=2)
      t[i][j] = getchar();
    getchar();
  }
  if(k == 1) {
    int gcnt = 0;
    for(int i = 0; i<2*h-1; ++i)
      for(int j = 1-(i%2), cnt = 0; cnt<(i%2)+w-1; ++cnt, j+=2)
        gcnt += t[i][j] == 'E';
    if(gcnt * 4 >= tot * 3) {
      puts("YES");
      for(int i = 0; i<h; ++i)
        for(int j = 0; j<w; ++j)
          printf("1%c", " \n"[j+1==w]);
    } else
      puts("NO");
    return 0;
  }
  bool sw = h > w;
  if(sw) {
    for(int i = 0; i<2*h-1; ++i)
      for(int j = 1-(i%2), cnt = 0; cnt<(i%2)+w-1; ++cnt, j+=2)
        if(j < i)
          swap(t[i][j], t[j][i]);
    swap(h, w);
  }
  do_row(0);
  for(int i = 1; i<h; ++i) {
    int gcnt = do_row(i);
    if(gcnt < (w+1)/2) {
      for(int cnt = 0; cnt<w; ++cnt)
        res[i][cnt] = 1 - res[i][cnt];
    }
  }
  puts("YES");
  if(sw) {
    for(int i = 0; i<w; ++i)
      for(int j = 0; j<h; ++j)
        printf("%d%c", res[j][i]+1, " \n"[j+1==h]);
  } else {
    for(int i = 0; i<h; ++i)
      for(int j = 0; j<w; ++j)
        printf("%d%c", res[i][j]+1, " \n"[j+1==w]);
  }
}