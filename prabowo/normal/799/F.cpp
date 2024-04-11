#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> gardens[N];

struct SegTree {
  int cnt[N << 2];
  int sum0[N << 2];
  long long sum1[N << 2];
 
  void update(int node, int l, int r, int ll, int rr, int val) {
    if (l > rr || r < ll) return;
    if (l >= ll && r <= rr) {
      cnt[node] += val;
      sum0[node] = (cnt[node] > 0 ? (r - l + 1) : (l == r ? 0 : sum0[node*2 + 1] + sum0[node*2 + 2]));
      sum1[node] = (cnt[node] > 0 ? 1LL * (l + r) * (r - l + 1) / 2 : (l == r ? 0 : sum1[node*2 + 1] + sum1[node*2 + 2]));
      return;
    }
 
    int mid = (l + r) >> 1;
 
    update(node*2 + 1, l, mid, ll, rr, val);
    update(node*2 + 2, mid+1, r, ll, rr, val);
    sum0[node] = (cnt[node] > 0 ? (r - l + 1) : sum0[node*2 + 1] + sum0[node*2 + 2]);
    sum1[node] = (cnt[node] > 0 ? 1LL * (l + r) * (r - l + 1) / 2 : sum1[node*2 + 1] + sum1[node*2 + 2]);
  }
} odd, even;

void updateOdd(int l, int r, int val) {
  odd.update(0, 0, m-1, l/2, (r+1)/2 - 1, val);
}

void updateEven(int l, int r, int val) {
  even.update(0, 0, m-1, (l+1)/2, r/2, val);
}

long long queryBeautiful(int l) {
  long long ret = odd.sum1[0] * 2 + odd.sum0[0] + even.sum1[0] * 2;
  ret = ret - 1LL * (l - 1) * (odd.sum0[0] + even.sum0[0]);
  return 1LL * (m - l) * (m - l + 1) / 2 - ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    if (l & 1) updateEven(l, r, 1);
    else updateOdd(l, r, 1);

    if (r - l & 1) {
      updateOdd(r+1, m-1, 1);
      updateEven(r+1, m-1, 1);
    }
    gardens[l].emplace_back(r);
  }

  long long ans = 0;
  int empty = 0;
  multiset<int> rodd, reven;
  for (int i = 0; i < m; ++i) {
    while (rodd.size() > 0 && *rodd.begin() < i) rodd.erase(rodd.begin());
    while (reven.size() > 0 && *reven.begin() < i) reven.erase(reven.begin());

    int maxi = -1;
    if (rodd.size() > 0) maxi = max(maxi, *rodd.rbegin());
    if (reven.size() > 0) maxi = max(maxi, *reven.rbegin());

    if (i & 1) {
      updateEven(i, maxi, 1);
      if (reven.size() > 0) {
        updateOdd(*reven.begin(), m-1, 1);
        updateEven(*reven.begin(), m-1, 1);
      }
    } else {
      updateOdd(i, maxi, 1);
      if (rodd.size() > 0) {
        updateOdd(*rodd.begin(), m-1, 1);
        updateEven(*rodd.begin(), m-1, 1);
      }
    }

    ans += queryBeautiful(i);
    // cerr << queryBeautiful(i) << endl;

    if (i & 1) {
      updateEven(i, maxi, -1);
      if (reven.size() > 0) {
        updateOdd(*reven.begin(), m-1, -1);
        updateEven(*reven.begin(), m-1, -1);
      }
    } else {
      updateOdd(i, maxi, -1);
      if (rodd.size() > 0) {
        updateOdd(*rodd.begin(), m-1, -1);
        updateEven(*rodd.begin(), m-1, -1);
      }
    }

    for (int r: gardens[i]) {
      if (i & 1) updateEven(i, r, -1);
      else updateOdd(i, r, -1);

      if (r - i & 1) {
        updateOdd(r+1, m-1, -1);
        updateEven(r+1, m-1, -1);
      }

      if (r & 1) rodd.insert(r);
      else reven.insert(r);
    }

    if (rodd.size() + reven.size() == 0) ++empty;
    else empty = 0;
    ans -= 1LL * empty * (empty + 1) / 2;
  }

  printf("%lld\n", ans);
  return 0;
}