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
		string s;
		cin >> s;
		bool ok=1;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (a[i]==a[j]&&s[i]!=s[j])
					ok=0;
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}