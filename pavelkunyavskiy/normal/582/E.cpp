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

const int N = 16;

typedef vector<int> data;

inline void add(int& x, int y) {
  if ((x += y) >= MOD) x -= MOD;
}

inline void sub(int& x, int y) {
  if ((x -= y) < 0) x += MOD;
}

inline int mult(int x, int y) {
  return (x * 1LL * y) % MOD;
}


void dzeta(data& x) {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < (1<<N); i++)
      if (i & (1<<k))
        add(x[i], x[i ^ (1<<k)]);
}

void undzeta(data& x) {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < (1<<N); i++)
      if (i & (1<<k))
        sub(x[i], x[i ^ (1<<k)]);
}

void reverse(data& x) {
  for (int i = 0; i < (1<<N); i++) {
    int other = ((1<<N) - 1) ^ i;
    if (i < other)
      swap(x[i], x[other]);
  }
}

vector<int> calc_or(data l, data r) {
  dzeta (l);
  dzeta (r);
  data result(1<<N);
  for (int i = 0; i < (1<<N); i++)
    result[i] = mult(l[i], r[i]);
  undzeta (result);
  return result;
}

vector<int> calc_and(data l, data r) {
  reverse (l);
  reverse (r);
  data result = calc_or (l, r);
  reverse(result);
  return result;
}


char s[1000];
int sptr;

data result_var[9];

data expr() {
  if (s[sptr] == '(') {
    sptr++;
    data resleft = expr ();
    assert(s[sptr++] == ')');
    char c = s[sptr];
    if (c != '|' && c != '&' && c != '?') {
      return resleft;
    }
    sptr++;
    assert(s[sptr++] == '(');
    data resright = expr ();
    assert(s[sptr++] == ')');
    if (c == '&') {
      return calc_and (resleft, resright);
    }
    if (c == '|') {
      return calc_or (resleft, resright);
    }
    assert(c == '?');
    vector<int> result_and = calc_and (resleft, resright);
    vector<int> result_or = calc_or (resleft, resright);

    for (int i = 0; i < (1 << N); i++)
      add (result_and[i], result_or[i]);
    return result_and;
  }
  if (s[sptr] == '?') {
    sptr++;
    return result_var[8];
  }
  if ('A' <= s[sptr] && s[sptr] <= 'D') {
    sptr++;
    return result_var[s[sptr - 1] - 'A'];
  }
  assert('a' <= s[sptr] && s[sptr] <= 'd');
  sptr++;
  return result_var[s[sptr - 1] - 'a' + 4];
}

int main() {
  #ifdef LOCAL
  assert(freopen (TASKNAME
           ".in", "r", stdin));
  assert(freopen (TASKNAME
           ".out", "w", stdout));
  #endif

  for (int i = 0; i < 4; i++) {
    result_var[i] = vector<int> (1 << N);
    int val = 0;
    for (int j = 0; j < N; j++)
      if (j & (1 << i))
        val |= (1 << j);
//    eprintf("%d -> %02x\n", i, val);
    result_var[i][val] = 1;
  }

  for (int i = 0; i < 4; i++) {
    result_var[i + 4] = vector<int> (1 << N);
    int val = 0;
    for (int j = 0; j < N; j++)
      if (!(j & (1 << i)))
        val |= (1 << j);
    result_var[i + 4][val] = 1;
  }

  result_var[8] = result_var[0];
  for (int i = 1; i < 8; i++)
    for (int j = 0; j < (1 << N); j++)
      add (result_var[8][j], result_var[i][j]);

  fgets (s, sizeof (s), stdin);

  data res = expr ();

  assert(s[sptr] == 0 || s[sptr] == '\r' || s[sptr] == '\n');

  int and_mask, xor_mask;
  and_mask = xor_mask = 0;

  int q;
  scanf ("%d", &q);

  for (int i = 0; i < q; i++) {
    int a, b, c, d, val;
    scanf ("%d %d %d %d %d", &a, &b, &c, &d, &val);
    int pos = a | (b << 1) | (c << 2) | (d << 3);
    and_mask |= (1 << pos);
    xor_mask |= (val << pos);
  }

  int ans = 0;
  for (int i = 0; i < (1 << N); i++)
    if ((i & and_mask) == xor_mask)
      add (ans, res[i]);

  printf ("%d\n", ans);
  return 0;
}