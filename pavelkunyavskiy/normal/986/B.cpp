#include <iostream>
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

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

using namespace std;

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

vector<int> bit;

void add(int x) {
  for (;x < (int)bit.size(); x = (x | (x + 1))) bit[x] += 1;
}

int get(int x) {
  int ans = 0;
  for (; x != -1; x = (x & (x + 1)) - 1) ans += bit[x];
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    --v[i];
  }

  int odd = (3 * n) % 2;
  assert(odd != (7 * n + 1) % 2);
  bit = vector<int>(n);

  int ans = 0;

  for (int i = n - 1; i >= 0; i--) {
    ans = (ans + get(v[i])) % 2;
    add(v[i]);
  }

  if (ans == odd) {
    printf("Petr\n");
  } else {
    printf("Um_nik\n");
  }

  return 0;
}