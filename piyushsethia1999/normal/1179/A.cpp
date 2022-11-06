#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

deque<int> d;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int p = -1, in = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] > p) {
			p = a[i];
			in = i;
		} 
		d.push_back(a[i]);
	}
	std::vector<int> v;
	int im = 0;
	int A[n + 1];
	int B[n + 1];
	while (d.front() != p) {
		A[im] = d.front();
		d.pop_front();
		B[im] = d.front();
		d.pop_front();
		if (A[im] > B[im]) {
			d.push_back(B[im]);
			d.push_front(A[im]);
		} else {
			d.push_front(B[im]);
			d.push_back(A[im]);	
		}
		im++;
	}
	d.pop_front();
	while (!d.empty()) {
		v.pb(d.front());
		d.pop_front();
	}
	for (int i = 0; i < q; ++i) {
		int t; cin >> t;
		t--;
		if (t < im) {
			cout << A[t] << " " << B[t] << "\n";
		} else {
			t -= im;
			cout << p << " " << v[t % (n - 1)] << "\n";
		}
	}
}