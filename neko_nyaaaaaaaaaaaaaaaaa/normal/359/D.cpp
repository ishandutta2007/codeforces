#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(300001);
vector<int> tree(1200001);
vector<int> tree2(1200001);

void build(int node, int start, int end) {
	if(start == end) {
            tree[node] = tree2[node] = a[start];
	} else {
		int mid = (start + end)/2;

	      build(2*node, start, mid);
	      build(2*node+1, mid+1, end);

	      tree[node] = __gcd(tree[2*node], tree[2*node+1]);
	      tree2[node] = min(tree2[2*node], tree2[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r) {
	if (r < start || end < l) {
		return 0;
	}
	if (l <= start && end <= r) {
		return tree[node];
	}
	int mid = (start+end)/2;
	return __gcd(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}

int quemin(int node, int start, int end, int l, int r) {
	if (r < start || end < l) {
		return INT_MAX;
	}
	if (l <= start && end <= r) {
		return tree2[node];
	}
	int mid = (start+end)/2;
	return min(quemin(2*node, start, mid, l, r), quemin(2*node+1, mid+1, end, l, r));
}

int check(int c) {
      for (int i = 1; i+c <= n; i++) {
            if (query(1, 1, n, i, i+c) == quemin(1, 1, n, i, i+c)) return 1;
      }
      return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);

      int lo = 0, hi = n-1;
      while (lo < hi) {
            int mid = (lo + hi + 1)/2;
            if (check(mid)) {
                  lo = mid;
            } else {
                  hi = mid - 1;
            }
      }
      vector<int> ans;
      for (int i = 1; i+lo <= n; i++) {
            if (query(1, 1, n, i, i+lo) == quemin(1, 1, n, i, i+lo)) ans.push_back(i);
      }
      cout << ans.size() << ' ' << lo << '\n';
      for (int i: ans) cout << i << " ";

	return 0;
}