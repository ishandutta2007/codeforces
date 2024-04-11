#include<bits/stdc++.h>
#define x1 qwerqwerqwerchem
#define y1 qwerqwerqqwwefqwerthan
#define x2 qwerqwerqwqewqegerga
#define y2 qwqwfeqweferqwerqwervl

using namespace std;

const int maxn = 1000005;

int a[maxn], b[maxn], d[maxn];
vector<int> nums;
vector<pair<int, int>> points[maxn];

long long lazy[maxn << 3];
pair<long long, int> tree[maxn << 2];

#define lc (x << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void push(int x) {
  tree[x].first += lazy[x];
  lazy[lc] += lazy[x];
  lazy[rc] += lazy[x];
  lazy[x] = 0;
}

void upd(int x, int l, int r, int u, int v, int val) {
  push(x);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[x] += val;
    push(x);
    return;
  }
  upd(lc, l, mid, u, v, val);
  upd(rc, mid + 1, r, u, v, val);
  tree[x] = max(tree[lc], tree[rc]);
}

void modify(int x, int l, int r, int pos) {
  if(l == r) {
    tree[x] = make_pair(nums[r], nums[r]);
    return;
  }
  if(pos <= mid) modify(lc, l, mid, pos);
  else modify(rc, mid + 1, r, pos);
  tree[x] = max(tree[lc], tree[rc]);
}

int main() {
  for(int i = 0; i < (maxn << 2); ++i) {
    tree[i].first = -1e18;
  }
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    int x, y, c; cin >> x >> y >> c;
    nums.emplace_back(x);
    nums.emplace_back(y);
    a[i] = x; b[i] = y; d[i] = c;
  }

  nums.emplace_back(0);
  nums.emplace_back((int)1e9 + 7);

  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  for(int i = 0; i < n; ++i) {
    a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
    b[i] = lower_bound(nums.begin(), nums.end(), b[i]) - nums.begin();
    points[max(a[i], b[i])].emplace_back(min(a[i], b[i]), d[i]);
  }


  int sz = nums.size();

  long long bestAns = -1e18;
  int x1 = -1, x2 = 0, y1 = 0, y2 = 0;

  for(int i = 0; i < sz; ++i) {
    modify(1, 0, sz - 1, i);
    for(auto p : points[i]) {
      upd(1, 0, sz - 1, 0, p.first, p.second);
    }

    auto now = tree[1];
    now.first -= nums[i];


    if(now.first > bestAns) {
      bestAns = now.first;
      x1 = y1 = now.second;
      x2 = y2 = nums[i];
    }
  }

  cout << bestAns << endl << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

  return 0;
}