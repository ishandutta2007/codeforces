// not my code: https://codeforces.com/contest/1642/submission/147442302
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ld long double;
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t,n,cnt,ans,temp1,temp2;
	ll a;
	multiset<ll>s;
	ll x;
	bool flag;
 
	cin >> t;
	while (t--) {
		cin >> n >> x;
		ans = 0;
		vector<ll>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> a;
			s.insert(a);
		}
		sort(v.begin(),v.end());
		auto c = s.begin();
		while (!s.empty()) {
			int d = *s.begin();
			if (s.count(d*x)) {
				s.erase(s.lower_bound(d*x));
				s.erase(s.lower_bound(d));
			}
			else {
				s.erase(s.lower_bound(d));
				++ans;
			}
		}
		cout << ans << "\n";
	}
}