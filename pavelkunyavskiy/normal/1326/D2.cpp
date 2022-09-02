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

const int MAXC = 1e6+100;

char buf[MAXC];

string best_pref(string s) {
  {
    string sr = s;
    reverse(s.begin(), s.end());
    s = s + '$' + sr;
  }
  vector<int> p(s.size());
  for (int i = 1; i < (int)p.size(); i++) {
    int &j = p[i];
    j = p[i - 1];
    while (j && s[j] != s[i]) {
      j = p[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
  }
  eprintf("%s -> %s\n", s.c_str(), s.substr(0, p.back()).c_str());
  return s.substr(0, p.back());
}


string best_suf(string s) {
  reverse(s.begin(), s.end());
  string ans = best_pref(std::move(s));
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  scanf("%*d");

  while (scanf("%s", buf) == 1) {
    int len = strlen(buf);
    int sz = 0;
    while (sz < len && buf[sz] == buf[len - sz - 1])
      sz++;
    string ans;
    if (sz == len) {
      ans = buf;
    } else {
      string b1 = best_pref(string(buf + sz, buf + len - sz));
      string b2 = best_suf(string(buf + sz, buf + len - sz));
      ans = string(buf, buf + sz) + (b1.size() <= b2.size() ? b2 : b1) +
            string(buf + len - sz, buf + len);
    }
    printf("%s\n", ans.c_str());
  }

  return 0;
}