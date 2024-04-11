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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		if (*min_element(a.begin(), a.end())<0) {
			cout << "No\n";
			continue;
		}
		for (int i=0; i<=100; ++i)
			if (find(a.begin(), a.end(), i)==a.end())
				a.push_back(i);
		cout << "Yes\n" << a.size() << "\n";
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}