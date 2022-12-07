#include <bits/stdc++.h>

using namespace std;
const int N = 200020;

int n;
long long p[N];

long long it[N << 2];
long long lazy[N << 3];

#define mid ((l + r) >> 1)

void toggle(int x) {
  it[x] += lazy[x];
  lazy[x + x] += lazy[x];
  lazy[x + x + 1] += lazy[x];
  lazy[x] = 0;
}

void inc(int x, int l, int r, int u, int v, long long val) {
  if(u > v) return;
  toggle(x);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[x] += val;
    toggle(x);
    return;
  }

  inc(x + x, l, mid, u, v, val);
  inc(x + x + 1, mid + 1, r, u, v, val);
  it[x] = min(it[x + x], it[x + x + 1]);
}

int find(int x, int l, int r) {
  toggle(x);
  if(l == r) {
    return r;
  }
  toggle(x + x);
  toggle(x + x + 1);


  int ret;
  if(it[x + x + 1] == 0) ret = find(x + x + 1, mid + 1, r);
  else ret = find(x + x, l, mid);

  it[x] = min(it[x + x], it[x + x + 1]);
  return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> p[i];
    inc(1, 1, n, i, i, p[i]);
  }

  vector < int > res(n + 1);


  for(int i = 1; i <= n; ++i) {
    int pos = find(1, 1, n);
    res[pos] = i;

    inc(1, 1, n, pos + 1, n, -i);
    inc(1, 1, n, pos, pos, 1e12);
  }

  for(int i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }
  return 0;
}