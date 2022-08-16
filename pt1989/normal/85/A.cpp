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
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;


int f(string x) {
  int r = 0;
  for (int i=0; i < (int)x.size(); i++) {
    r = r*2 + (x[i] - '0');
  }
  return r;
}

int n;
bool good[16];
int dp[102][16];
int solve(int pos, int mask) {
  if (pos == n)
    return mask == 0;
  if (pos && mask == 0) {
    return 0;
  }
  int &ret = dp[pos][mask];
  if (~ret)
    return ret;
  ret = 0;
  for (int cm=0; cm < 16; cm++)
  if ((cm & mask) == 0) {
    if (good[cm | mask]) {
      ret |= solve(pos+1, cm);
    }
  }
  return ret; 
}

int id[4][102];
int idptr = 0;
void recon(int pos, int mask) {
  if (pos == n) return;
  //cout << pos << " " << mask << endl;
  for (int cm=0; cm < 16; cm++)
  if ((cm & mask) == 0) {
    if (good[cm | mask]) {
      if (solve(pos+1, cm)) {
        for (int j=0; j < 4; j++) 
        if (cm & 1 << j) {
          id[j][pos] = id[j][pos+1] = idptr++;
        }
        for (int j=0; j < 4; j++)
        if ( (cm | mask) & 1<<j );
        else {
          id[j][pos] = id[j+1][pos] = idptr++;
          j++;
        }
        return recon(pos+1, cm);
      }
    }
  }
}

int main(int argc, char** argv) {
	good[ f("1111") ] = 1;
  good[ f("0011") ] = 1;
  good[ f("1100") ] = 1;
  good[ f("1001") ] = 1;
  good[ f("0000") ] = 1;
  cin>>n;
  fill(dp, -1);
  if (solve(0, 0)) {
    recon(0, 0);
    for (int i=0; i < 4; i++) {
      for (int j=0; j < n; j++) {
        cout << (char)( id[i][j] % 26  + 'a' );
      }
      cout << endl;
    }
  } else {
    cout << -1 << endl;
  }
	return 0;
}