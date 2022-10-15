#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
 
const int mxn = 100006;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
template<class T> using rset = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;
 
int count(rset<int> &s, int l, int r) {
	return s.order_of_key(*s.upper_bound(r)) - s.order_of_key(*s.lower_bound(l));
}
 
int n;
rset<int> s;
set<int> p[mxn];
 
int main() {
    fio;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		s.insert(i);
		int x;
		cin>>x;
		p[x].insert(i);
	}
	
	s.insert(INT_MAX);
	
	ll ans = 0;
	int x = 1;
	for (auto &i : p) {
		while (!i.empty()) {
			int y;
			if (i.lower_bound(x) != i.end()) {
				y = *i.lower_bound(x);
				ans += count(s, x, y);
			} else {
				y = *i.begin();
				ans += count(s, x, n);
				ans += count(s, 1, y);
			}
			s.erase(y);
			i.erase(y);
			x = y;
		}
	}
	
	cout << ans << endl;
}