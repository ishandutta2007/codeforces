#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> s;
	int cnt=0;
	for (int i=0; i+2<n; ++i)
		if (s.substr(i, 3)=="abc")
			++cnt;
	while(q--) {
		int i;
		char c;
		cin >> i >> c, --i;
		for (int j : {i-2, i-1, i, i+1, i+2})
			if (j>=0&&j+2<n)
				cnt-=s.substr(j, 3)=="abc";
		s[i]=c;
		for (int j : {i-2, i-1, i, i+1, i+2})
			if (j>=0&&j+2<n)
				cnt+=s.substr(j, 3)=="abc";
		cout << cnt << "\n";
	}
	return 0;
}