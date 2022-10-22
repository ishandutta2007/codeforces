#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> a(26);
	for (int i=0; i<26; ++i)
		a[i]=(char)('a'+i);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		bool ok=1;
		for (string x : a)
			if (ok&&s.find(x)==string::npos)
				cout << x << "\n", ok=0;
		for (string x : a)
			for (string y : a)
				if (ok&&s.find(x+y)==string::npos)
					cout << x+y << "\n", ok=0;
		for (string x : a)
			for (string y : a)
				for (string z : a)
					if (ok&&s.find(x+y+z)==string::npos)
						cout << x+y+z << "\n", ok=0;
	}
	return 0;
}