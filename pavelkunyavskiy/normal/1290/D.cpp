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

struct interactor {
  bool local;
  int n, k;
  vector<int> a;
  queue<int> q;
  map<int, int> s;
  int ops;

  void init() {
    scanf("%d%d", &n, &k);
    if (local) {
      a.resize(n);
      for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
      }
    }
  }

  void reset() {
    printf("R\n");
    fflush(stdout);
    if (local) {
      q = queue<int>();
      s.clear();
    }
  }

  bool query(int x) {
    ops++;
//    assert(ops <= 3 * n * n / (2 * k));
    printf("? %d\n", x + 1);
    fflush(stdout);
    if (local) {
      x = a[x];
      bool ans = s[x] > 0;
      s[x]++;
      q.push(x);
      if ((int)q.size() > k) {
        s[q.front()]--;
        q.pop();
      }
      return ans;
    } else {
      char res;
      scanf(" %c", &res);
      if (res == 'E') exit(0);
      return res == 'Y';
    }
  }

  void answer(int x) {
    printf("! %d\n", x);
    if (local) {
      assert((int)set<int>(a.begin(), a.end()).size() == x);
    } else {
      fflush(stdout);
    }
  }
};

interactor jury;


vector<int> solve_all(int l, int r) {
  if (r - l == jury.k) {
    vector<int> ans;
    jury.reset();
    for (int i = l; i < r; i++) {
      if (!jury.query(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
  vector<int> a = solve_all(l, (l + r) / 2);
  vector<int> b = solve_all((l + r) / 2, r);

  vector<vector<int>> as;
  vector<vector<int>> bs;

  for (int i = 0; i < (int)a.size(); i += jury.k) {
    as.emplace_back(a.begin() + i, a.begin() + min((int)a.size(), i + jury.k));
  }
  for (int i = 0; i < (int)b.size(); i += jury.k) {
    bs.emplace_back(b.begin() + i, b.begin() + min((int)b.size(), i + jury.k));
  }

  auto filter = [&](vector<int>& a, vector<int>&b) {
    if (a.empty() || b.empty()) return;
    auto push_all = [](vector<int> &a) {
      vector<int> temp;
      for (int i : a) {
        if (!jury.query(i)) {
          temp.push_back(i);
        }
      }
      a = temp;
    };
    assert((int)a.size() <= jury.k);
    assert((int)b.size() <= jury.k);
    jury.reset();
    if ((int)a.size() + (int)b.size() <= jury.k + 1) {
      push_all(a);
      push_all(b);
      return;;
    }
    if (jury.local) {
      printf("Berfore:");
      for (int x : a) printf(" %d[%d]", x, jury.a[x]);
      printf("|");
      for (int x : b) printf(" %d[%d]", x, jury.a[x]);
      printf("\n");
    }
    for (int i : a) {
      jury.query(i);
    }
    int aback = a.back();
    for (int i = (int)a.size(); i <= jury.k; i++) {
      jury.query(aback);
    }
    a.pop_back();

    int obsize = b.size();
    push_all(b);
    for (int i = obsize; i < jury.k; i++) {
      jury.query(aback);
    }
    push_all(a);
    if (a.empty() || a.back() != aback) {
      a.push_back(aback);
    }
    if (jury.local) {
      printf("After:");
      for (int x : a) printf(" %d[%d]", x, jury.a[x]);
      printf("|");
      for (int x : b) printf(" %d[%d]", x, jury.a[x]);
      printf("\n");
    }

  };

  if (jury.local) {
    printf("==========\n");
  }
  for (auto &aa : as) {
    for (auto &bb : bs) {
      int ops = jury.ops;
      filter(aa, bb);
      if (jury.ops - ops > 3 * jury.k) {
        eprintf("before = %d, ops = %d, diff = %d\n", jury.ops, ops, jury.ops - ops);
        assert(0);
      }
    }
  }

  vector<int> ans;
  for (auto& part : as) {
    ans.insert(ans.end(), part.begin(), part.end());
  }
  for (auto& part : bs) {
    ans.insert(ans.end(), part.begin(), part.end());
  }

  if (jury.local) {
    if (ans.size() != set<int>(jury.a.begin() + l, jury.a.begin() + r).size()) {
      eprintf("fail on %d..%d\n", l, r);
      assert(0);
    }
  }

  return ans;

}

// 1 2 3 0 1
// 2 vs [1]
// 3 vs [1]

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

#ifdef LOCAL
  jury.local = true;
#endif
  jury.init();

  vector<int> ans = solve_all(0, jury.n);
  jury.answer(ans.size());
  eprintf("%d %d %lf\n", jury.ops, 4 * jury.n * jury.n / (2 * jury.k), jury.ops *1.0 / (jury.n * jury.n / (2 * jury.k)));

  return 0;
}