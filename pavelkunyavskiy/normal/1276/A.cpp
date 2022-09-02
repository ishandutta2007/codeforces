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
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

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

char s[2'000'000];

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int t;
  scanf("%d", &t);
  for (int _ = 0; _ < t; _++) {
    scanf("%s", s);
    int n = strlen(s);
    vector<int> rem;
    for (int i = 0; i < n; ) {
      if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
        if (s[i + 3] == 'o') {
          rem.push_back(i + 1);
          i = i + 2;
        } else {
          rem.push_back(i + 2);
          i = i + 3;
        }
      } else if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
        rem.push_back(i + 1);
        i = i + 2;
      } else {
        i = i + 1;
      }
    }
    printf("%d\n", (int)rem.size());
    for (int x : rem) {
      printf("%d ", x + 1);
    }
    printf("\n");
  }

  return 0;
}