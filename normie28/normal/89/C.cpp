
// Problem : C. Chip Play
// Contest : Codeforces - Codeforces Beta Round #74 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/89/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
 
const int MAX_HW = 5000;
const char dcs[] = "RULD";
const int dxs[] = { 1, 0, -1, 0 }, dys[] = { 0, -1, 0, 1 };
 
 
int dcmap[128];
char s[MAX_HW + 4], fs0[MAX_HW], fs1[MAX_HW];
short nbs0[MAX_HW][4], nbs1[MAX_HW][4];
 
 
inline bool inside(int x, int y, int w, int h) {
  return x >= 0 && x < w && y >= 0 && y < h;
}
 
inline void remcell(short (*nbs)[4], int p) {
  for (int di0 = 0; di0 < 4; di0++) {
    int di1 = (di0 ^ 2), p0 = nbs[p][di0];
    if (p0 >= 0) nbs[p0][di1] = nbs[p][di1];
  }
}
 
 
int main() {
	fio;
  for (int i = 0; i < 4; i++) dcmap[dcs[i]] = i;
  dcmap['.'] = -1;
 
  int h, w;
  cin>>h>>w;
 
  int hw = h * w;
  int dps[4] = { 1, -w, -1, w };
 
  for (int y = 0, p = 0; y < h; y++) {
  	cin>>s;
    for (int x = 0; x < w; x++, p++) {
      fs0[p] = dcmap[s[x]];
      for (int di = 0; di < 4; di++)
	nbs0[p][di] =
	  inside(x + dxs[di], y + dys[di], w, h) ? p + dps[di] : -1;
    }
  }
 
  for (int p = 0; p < hw; p++)
    if (fs0[p] < 0) remcell(nbs0, p);
      
  int maxr = 0, maxc = 0;
  for (int st = 0; st < hw; st++)
    if (fs0[st] >= 0) {
      int p = st, r = 0;
      memcpy(fs1, fs0, sizeof(fs0));
      memcpy(nbs1, nbs0, sizeof(nbs0));
 
      while (p >= 0) {
	int ndi = fs1[p];
	fs1[p] = -1;
	remcell(nbs1, p);
	
	r++;
	p = nbs1[p][ndi];
      }
 
      if (maxr < r) maxr = r, maxc = 1;
      else if (maxr == r) maxc++;
    }
 
 cout<<maxr<<' '<<maxc;
}