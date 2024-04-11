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
		string s;
		cin >> n >> s;
		vector<int> T, M;
		for (int i=0; i<n; ++i)
			s[i]=='T'?T.push_back(i):M.push_back(i);
		if (T.size()!=2*M.size()) {
			cout << "NO\n";
			continue;
		}
		bool ok=1;
		for (int i=0; i<n/3; ++i)
			ok&=T[i]<M[i]&&M[n/3-i-1]<T[2*n/3-i-1];
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}