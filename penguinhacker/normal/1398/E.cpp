#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll ans;
multiset<int> a, b, c; // lightning, largest, not largest

void norm() {
	bool ok=1;
	while(ok) {
		ok=0;
		while(b.size()<a.size()) {
			int x=*c.rbegin();
			c.erase(--c.end());
			b.insert(x);
			ans+=x, ok=1;
		}
		while(b.size()>a.size()) {
			int x=*b.begin();
			b.erase(b.begin());
			c.insert(x);
			ans-=x, ok=1;
		}
		while(b.size()&&c.size()&&*b.begin()<*c.rbegin()) {
			int x=*b.begin(), y=*c.rbegin();
			b.erase(b.begin()), c.erase(--c.end());
			b.insert(y), c.insert(x);
			ans+=y-x, ok=1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--) {
		int t, x;
		cin >> t >> x;
		if (x>0) { // add
			ans+=x;
			if (t)
				a.insert(x);
			c.insert(x);
		} else { // erase
			x*=-1, ans-=x;
			if (t)
				a.erase(a.find(x));
			if (c.find(x)!=c.end())
				c.erase(c.find(x));
			else
				b.erase(b.find(x)), ans-=x;
		}
		norm();
		if (b.empty()&&c.empty())
			cout << "0\n";
		else if (c.empty())
			cout << ans-*b.begin() << "\n";
		else if (a.size()&&*a.begin()>*c.rbegin())
			cout << ans+*c.rbegin()-*a.begin() << "\n";
		else
			cout << ans << "\n";
	}
	return 0;
}