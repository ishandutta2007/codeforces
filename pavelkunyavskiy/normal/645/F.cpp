//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "F"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
	~__timestamper(){
        TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif


typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

const int MAXN = 1000010;
int coef[MAXN];

vector<int> divisors[MAXN];
int cnt[MAXN];
int value[MAXN];
int inv[MAXN];
int ans;
int k;

void add(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
void sub(int& a, int b) {
  if ((a -= b) < 0) a += MOD;
}

int mult(int a, int b) {
  return (int) ((a * 1LL * b) % MOD);
}

void add_divisor(int d) {
  cnt[d]++;
  if (cnt[d] < k) return;
  if (cnt[d] == k) {
    value[d] = coef[d];
    add(ans, coef[d]);
    return;
  }
  sub(ans, value[d]);
  value[d] = mult(value[d], cnt[d]);
  value[d] = mult(value[d], inv[cnt[d] - k]);
  add(ans, value[d]);
}

int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif

  inv[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    inv[i] = (MOD - MOD / i * 1LL * inv[MOD % i]) % MOD;
    if (inv[i] < 0) inv[i] += MOD;
  }

  for (int i = 1; i < MAXN; i++) {
     divisors[i].push_back(i);
     for (int j = 2*i; j < MAXN; j += i) {
       divisors[j].push_back(i);
     }
  }

  for (int i = 1; i < MAXN; i++) {
    coef[i] = i;
    for (int j : divisors[i])
      if (i != j)
        coef[i] -= coef[j];
  }

  int cnt = 0;
  for (int i = 0; i < MAXN; i++)
    if (coef[i] != 0)
      cnt++;

  int n, q;
  scanf("%d%d%d", &n, &k, &q);

  for (int i = 0; i < n + q; i++) {
    int x;
    scanf("%d",&x);
    for (int d : divisors[x])
      add_divisor(d);
    if (i >= n) {
      printf("%d\n", ans);
    }
  }
  return 0;
}