#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int it[N << 2];
int lazy[N << 3];

void toggle(int x) {
  it[x] += lazy[x];
  lazy[x + x] += lazy[x];
  lazy[x + x + 1] += lazy[x];
  lazy[x] = 0;
}

#define mid ((l + r) >> 1)

void update(int x, int l, int r, int u, int v, int val) {
  toggle(x);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[x] += val;
    toggle(x);
    return;
  }
  update(x + x, l, mid, u, v, val);
  update(x + x + 1, mid + 1, r, u, v, val);
  it[x] = min(it[x + x], it[x + x + 1]);
}

int binsearch(int x, int l, int r) {
  toggle(x);
  if(it[x] >= 0) return -1;
  if(l == r) return r;

 // cout << l << " " << r << " " << it[x + x + 1] << " " << lazy[x + x + 1] << endl;

  toggle(x + x);
  toggle(x + x + 1);

  int ans;
  if(it[x + x + 1] < 0) {
    ans = binsearch(x + x + 1, mid + 1, r);
  }
  else {
    ans = binsearch(x + x, l, mid);
  }
  it[x] = min(it[x + x], it[x + x + 1]);
  return ans;
}

int query(int x, int l, int r, int p) {
  if(l == r) return it[x] + lazy[x];
  if(p <= mid) return lazy[x] + query(x + x, l, mid, p);
  return lazy[x] + query(x + x + 1, mid + 1, r, p);
}

int a[N], b[N];

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, m, q;
  cin >> n >> m;
  
  for(int i = 1; i <= n; ++i) {
    int x; cin >> x; a[i] = x;
    update(1, 1, N - 1, 1, x, -1);
  }

  for(int i = 1; i <= m; ++i) {
    int x; cin >> x; b[i] = x;
    update(1, 1, N - 1, 1, x, 1);
  }

// /  cout << query(1, 1, N - 1, 8) << endl;

  cin >> q;
  while(q--) {
    int t, p, x;
    cin >> t >> p >> x;

    if(t == 1) {
      update(1, 1, N - 1, 1, a[p], 1);
      update(1, 1, N - 1, 1, a[p] = x, -1);
    }
    else {
      update(1, 1, N - 1, 1, b[p], -1);
      update(1, 1, N - 1, 1, b[p] = x, 1);
    }

    cout << binsearch(1, 1, N - 1) << "\n";
  }

  return 0;
}