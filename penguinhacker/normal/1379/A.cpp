#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int cmp(string s) {
	int cnt=0;
	for (int i=0; i<s.size()-6; ++i)
		if (s.substr(i, 7)=="abacaba")
			++cnt;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		string s, need="abacaba";
		cin >> n >> s;
		int cnt=cmp(s);
		if (cnt>1) {cout << "NO\n"; continue;}
		if (cnt==1) {
			cout << "YES\n";
			for (int i=0; i<n; ++i) cout << (s[i]=='?'?'z':s[i]);
			cout << '\n';
			continue;
		}
		bool pos=0;
		for (int i=0; i<n-6; ++i) {
			bool b=1;
			for (int j=0; j<7; ++j)
				if (s[i+j]!='?'&&s[i+j]!=need[j]) {
					b=0;
					break;
				}
			if (b) {
				string s2=s;
				for (int j=0; j<7; ++j)
					s2[i+j]=need[j];
				if (cmp(s2)==1) {
					for (int j=0; j<7; ++j)
						s[i+j]=need[j];
					pos=1;
					break;
				}
			}
		}
		if (!pos) {cout << "NO\n"; continue;}
		cout << "YES\n";
		for (int i=0; i<n; ++i)
			cout << (s[i]=='?'?'z':s[i]);
		cout << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/