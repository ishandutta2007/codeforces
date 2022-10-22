#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
ostream& operator<< (ostream& out, vector<int> v) {
	out << '[';
	for (int i=0; i<v.size(); ++i) {
		out << v[i];
		if (i<v.size()-1) out << ", ";
	}
	return out << "]\n";
}

int n, k, a[100000];

void test_case() {
	cin >> n >> k;
	bool seen=0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		seen|=a[i]==k;
	}
	if (!seen) {
		cout << "no\n";
		return;
	}
	if (n==1&&seen) {
		cout << "yes\n";
		return;
	}
	for (int i=0; i<n; ++i) for (int j=i+1; j<n&&j<=i+2; ++j)
		if (a[i]>=k&&a[j]>=k) {
			cout << "yes\n";
			return;
		}
	cout << "no\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/