#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		set<ar<int, 2>> s;
		int last=2e9;
		for (int i=0; i<n; ++i) {
			cin >> a[i];
			if (a[i]<last) {
				s.insert({-a[i], i});
				last=a[i];
			}
		}
		while(m--) {
			int i, x;
			cin >> i >> x, --i;
			s.erase({-a[i], i});
			a[i]-=x;
			auto it=s.insert({-a[i], i}).first;
			if (next(it)!=s.end()&&(*next(it))[1]<i||it!=s.begin()&&(*prev(it))[0]==-a[i]) {
				s.erase(it);
			} else {
				while(it!=s.begin()&&(*prev(it))[1]>i)
					s.erase(prev(it));
				while(next(it)!=s.end()&&(*next(it))[0]==-a[i])
					s.erase(next(it));
			}
			cout << s.size() << " ";
			//for (ar<int, 2> i : s)
			//	cout << "[" << i[0] << ", " << i[1] << "] ";
			//cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}