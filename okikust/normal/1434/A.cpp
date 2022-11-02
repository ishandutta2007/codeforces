#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int n;
	int x, y;
	int s, ans;
	int sz;
	vector<int>a;
	vector<int>b;
	set<int>st;
	set<int>::iterator itr;
	vector<int>c;
	rep(i, 6) {
		cin >> x;
		a.pb(x);
	}
	cin >> n;
	rep(i, n) {
		cin >> x;
		b.pb(x);
		st.insert(x);
	}
	sort(all(a));
	sort(all(b));
	rep(i, 6) {
		rep(j, n) {
			if ((b[j] - a[i]) <= (b[0] - a[0]))c.pb(b[j] - a[i]);
		}
	}
	ans = 2000000000;
	sz = c.size();
	rep(i, sz) {
		s = 0;
		rep(j, 5) {
			itr = st.lower_bound(a[j] + c[i]);
			if (itr == st.end())break;
			itr = st.lower_bound(a[j + 1] + c[i]);
			if (itr != st.begin()) {
				itr--;
				y = *itr;
				s = max(s, y - a[j] - c[i]);
			}
		}
		itr = st.lower_bound(a[5] + c[i]);
		if (itr != st.end()) {
			itr = st.end();
			itr--;
			y = *itr;
			s = max(s, y - a[5] - c[i]);
		}
		ans = min(ans, s);
	}
	cout << ans << endl;

	return 0;
}