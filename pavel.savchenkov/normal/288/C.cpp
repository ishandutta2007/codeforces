#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = (int) 1e6 + 10;

struct node {
  int bit, cnt, num;
  node *l, *r;

  node () { l = r = NULL; }

  node (int bit) : bit(bit), cnt(cnt), num(num) { l = r = NULL; cnt = 0; num = -1; }

  void upd() {
    cnt = 0;
    if  (l && l->cnt == 0) l = NULL;
    if  (r && r->cnt == 0) r = NULL;
    if  (l) cnt += l->cnt;
    if  (r) cnt += r->cnt;
  }

  int go (int val) {
    if  (bit == -1) {
      cnt--;
      return num;
    }

    int curbit = (val >> bit) & 1;
    int ret = -1;

    if  (l && (!r || curbit == 1)) {
      ret = l->go(val);
    }

    if  (r && (!l || curbit == 0)) {
      ret = r->go(val);
    }

    upd();
    return ret;
  }

  void add (int val) {
    if  (bit == -1) {
      num = val;
      cnt++;
      return;
    }

    int curbit = (val >> bit) & 1;
    
    if  (curbit == 1) {
      if  (!r) r = new node(bit - 1);
      r->add(val);
    } else {
      if  (!l) l = new node(bit - 1);
      l->add(val);
    }

    upd();
  }
};

int n;

node *root;

int ans[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  root = new node(31);
  
  for (int i = 0; i <= n; i++)
    root->add(i);

  ll m = 0;
  for (int i = 0; i <= n; i++) {
    ans[i] = root->go(i);
    m += 1ll * (i ^ ans[i]);
  }

  cout << m << '\n';
  for (int i = 0; i <= n; i++)
    printf("%d ", ans[i]);

  return 0;
}