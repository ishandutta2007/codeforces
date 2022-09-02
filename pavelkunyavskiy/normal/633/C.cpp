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

#define TASKNAME "C"

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

struct node {
    int sid;
    int next[26];
};
const int MAXMEM = 1010000;

node mem[MAXMEM];
int memptr;

const int MAXN = 10100;

int p[MAXN];
int dp[MAXN];

vector<string> val;

char buf[MAXMEM];
char buf2[MAXMEM];

void solve(int n) {
  if (n == 0) return;
  while(n < 0);
  assert(dp[n]);
  solve(n - (int) val[p[n]].size());
  printf("%s ", val[p[n]].c_str());
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  memset(mem, -1, sizeof(mem));

  int n;
  scanf("%d%s",&n, buf);

  int m;
  scanf("%d",&m);
  for (int i = 0; i < m; i++) {
    scanf("%s", buf2);
    val.push_back(buf2);
    int v = 0;
    for (int j = 0; buf2[j]; j++) {
      char c = tolower(buf2[j]);
      if (mem[v].next[c - 'a'] == -1) {
        mem[v].next[c - 'a'] = ++memptr;
      }
      v = mem[v].next[c - 'a'];
    }
    mem[v].sid = i;
  }

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int v = 0;
    for (int j = i - 1; j >= 0; j--) {
      v = mem[v].next[buf[j]-'a'];
      if (v == -1) break;
      if (mem[v].sid != -1 && dp[j]) {
        while ((int)val[mem[v].sid].size() != i - j);
        dp[i] = 1;
        p[i] = mem[v].sid;
        break;
      }
    }
  }

  while(!dp[n]);
  solve(n);
  printf("\n");
  return 0;
}