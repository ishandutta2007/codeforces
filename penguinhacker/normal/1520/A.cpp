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
		vector<bool> oc(26);
		bool ok=1;
		for (int i=0; i<n; ++i) {
			int x=s[i]-'A';
			if (!oc[x]) {
				oc[x]=1;
			} else {
				if (s[i]^s[i-1]) {
					ok=0;
					break;
				}
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}