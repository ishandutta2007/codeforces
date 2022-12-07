#include<bits/stdc++.h>

using namespace std;

const int maxn = 2000005;

int n;
int tmin[maxn << 3];
int tmax[maxn << 3];
int lazy[maxn << 3];

#define lc (x << 1)
#define rc (x << 1 | 1)
#define mid ((l + r) >> 1)

void push(int x) {
  tmax[x] += lazy[x];
  tmin[x] += lazy[x];
  lazy[lc] += lazy[x];
  lazy[rc] += lazy[x];
  lazy[x] = 0;
}

void update(int x, int l, int r, int u, int v, int val) {
  push(x);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[x] = val;
    push(x);
    return;
  }
  update(lc, l, mid, u, v, val);
  update(rc, mid + 1, r, u, v, val);
  tmax[x] = max(tmax[lc], tmax[rc]);
  tmin[x] = min(tmin[lc], tmin[rc]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  string s(maxn + 5, ' ');

  int pos = maxn / 2, all = 0;


  for(int i = 1; i <= n; ++i) {
    char c; cin >> c;


    if(c == 'L') --pos;
    else if(c == 'R') ++pos;
    else if(c == '(') {
      int val = 1;
      if(s[pos] == '(') val = 0;
      if(s[pos] == ')') val++;
      update(1, 1, maxn - 1, pos, maxn - 1, val);
      all += val;
      s[pos] = c;
    }
    else if(c == ')') {
      int val = -1;
      if(s[pos] == ')') val = 0;
      if(s[pos] == '(') val--;
      update(1, 1, maxn - 1, pos, maxn - 1, val);
      all += val;
      s[pos] = c;
    }
    else {
      int val = 0;
      if(s[pos] == ')') val = 1;
      if(s[pos] == '(') val = -1;
      update(1, 1, maxn - 1, pos, maxn - 1, val);
      all += val;
      s[pos] = c;
    }

    if(tmin[1] == 0 && all == 0) cout << tmax[1] << " ";
    else cout << -1 << " ";

    pos = max(pos, maxn / 2);
  }

  return 0;
}