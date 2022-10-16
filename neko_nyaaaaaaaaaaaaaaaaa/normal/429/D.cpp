#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> point;
#define x first
#define y second

int n;
vector<point> a;
double ans = 1e18;

double dist(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool cmp(point a, point b) {
	return a.y < b.y;
}

void solve(int l, int r) {
      if (r <= l) return;
      if (r == l+1) {
            ans = min(ans, dist(a[l], a[r]));
            if (!cmp(a[l], a[r])) swap(a[l], a[r]);
      } else {
            int mid = (l + r)/2;
            ll midx = a[mid].x;

            solve(l, mid);
            solve(mid+1, r);

            vector<point> tmp;
		merge(a.begin() + l, a.begin() + mid + 1, a.begin() + mid + 1, a.begin() + r + 1, back_inserter(tmp), cmp);
		copy(tmp.begin(), tmp.begin() + r - l + 1, a.begin() + l);

		tmp.clear();
		for (int i = l; i <= r; i++) {
			if (abs(a[i].x - midx) < ans) {
				for (int j = int(tmp.size()) - 1; j >= 0 && tmp[j].y > a[i].y - ans; j--) {
					ans = min(ans, dist(a[i], tmp[j]));
				}
				tmp.push_back(a[i]);
			}
		}
      }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      a.resize(n);
      vector<ll> p(n);
      for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (i) p[i] += p[i-1];
            a[i] = {i, p[i]};
      }
      sort(a.begin(), a.end());
      solve(0, n-1);

      cout << fixed << setprecision(0) << ans*ans;

	return 0;
}