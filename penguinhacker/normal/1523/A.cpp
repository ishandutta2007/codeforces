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
		string s;
		cin >> n >> m >> s;
		m=min(n, m);
		while(m--) {
			string s2=s;
			for (int i=0; i<n; ++i)
				if (s[i]=='0'&&((i>0&&s[i-1]=='1')^(i+1<n&&s[i+1]=='1')))
					s2[i]='1';
			s=s2;
		}
		cout << s << "\n";
	}
	return 0;
}