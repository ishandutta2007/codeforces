#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 400010;

int n;
int a[N];
int T[N << 2];

void build(int x, int l, int r) {
  if(l == r) {
    T[x] = a[r];
    return;
  }
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
  T[x] = min(T[x + x], T[x + x + 1]);
}

int find_left(int x, int l, int r, int u, int v, int val) {
  if(l > v || r < u || T[x] >= val) return -1;
  if(l == r) return r;
  int fl = find_left(x + x, l, mid, u, v, val);
  if(fl != -1) return fl;
  return find_left(x + x + 1, mid + 1, r, u, v, val);
}

int find_right(int x, int l, int r, int u, int v, int val){
  if(l > v || r < u || T[x] >= val) return -1;
  if(l == r) return r;
  int fr = find_right(x + x + 1, mid + 1, r, u, v, val);
  if(fr != -1) return fr;
  return find_right(x + x, l, mid, u, v, val);
}


int depth[N << 2];
int lazy[N << 3];

void toggle(int x) {
  depth[x] += lazy[x];
  lazy[x + x] += lazy[x];
  lazy[x + x + 1] += lazy[x];
  lazy[x] = 0;
}

void upd(int x, int l, int r, int u, int v, int val) {
  if(u > v) return;
  toggle(x);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[x] += val;
    toggle(x);
    return;
  }
  upd(x + x, l, mid, u, v, val);
  upd(x + x + 1, mid + 1, r, u, v, val);
  depth[x] = max(depth[x + x], depth[x + x + 1]);
}

int query(int x, int l, int r, int pos) {
  if(l == r) return depth[x] + lazy[x];
  if(pos <= mid) return query(x + x, l, mid, pos) + lazy[x];
  return query(x + x + 1, mid + 1, r, pos) + lazy[x];
}

int pos[N];
int ls[N], rs[N];
stack < int > st;

int height[N + N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  int m = n + n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
    a[i + n] = a[i];
  }

  for(int i = 1; i <= n; ++i) {
    while(!st.empty() && a[st.top()] > a[i]) {
      rs[st.top()] = i;
      st.pop();
    }
    if(st.empty()) ls[i] = -1;
    else ls[i] = st.top();
    st.push(i);
  }

  while(!st.empty()) {
    rs[st.top()] = -1;
    st.pop();
  }

  height[pos[1]] = 1;

  for(int i = 2; i <= n; ++i){
    int p = pos[i];
    int par = ls[p];


    if(par == -1) par = rs[p];
    if(rs[p] != -1 && a[rs[p]] > a[par]) par = rs[p];
    height[p] = height[par] + 1;
  }


  for(int i = 1; i <= n; ++i) {
    upd(1, 1, m, i, i, height[i]);
  }

  build(1, 1, m);

  pair < int, int > ans = make_pair(depth[1], 0);

  for(int i = 1; i < n; ++i) {
    /// delete i and insert it to the back
    int val = a[i];

    {
      int pos = find_left(1, 1, m, i, i + n, val);
      if(pos == -1) pos = i + n;
      upd(1, 1, m, i + 1, pos - 1, -1);
      upd(1, 1, m, i, i, - N - N);
    }

    {
      int pos = find_right(1, 1, m, i, i + n, val);
      if(pos != -1) upd(1, 1, m, pos + 1, i + n - 1, 1);
      else upd(1, 1, m, i + 1, i + n - 1, 1);

      if(pos != -1) upd(1, 1, m, i + n, i + n, query(1, 1, m, pos) + 1);
      else upd(1, 1, m, i + n, i + n, 1);
    }
    ans = min(ans, make_pair(depth[1], i));

  }

  cout << ans.first << " " << ans.second << endl;

  return 0;
}