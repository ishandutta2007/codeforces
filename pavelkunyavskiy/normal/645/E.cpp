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

#define TASKNAME "E"

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

int last[26];

char s[2000100];

int sum[26];
int k;

void add(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

int getsum() {
  int a = 0;
  for (int i = 0; i < k; i++)
    add(a, sum[i]);
  return a;
}

int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif
  int n;
  scanf("%d%d", &n, &k);

  scanf("%s", s);
  int m = strlen(s);
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n + m; i++) {
    if (i >= m) {
      s[i] = 'a' + (min_element(last, last + k) - last);
    }
    last[s[i] - 'a'] = i;
  }

  for (int i = n + m - 1; i >= 0; i--) {
    sum[s[i] - 'a'] = (getsum() + 1) % MOD;
  }

  printf("%d\n", (getsum() + 1) % MOD);


  return 0;
}